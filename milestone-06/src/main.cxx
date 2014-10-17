
#include <languages/lua/luamachine.h>
#include <languages/lua/converter.h>
#include <languages/lua/header.h>
#include <languages/lua/wrap/function.h>
#include <languages/lua/wrap/module.h>
#include <languages/lua/wrap/variable.h>

#include <opa/script.h>
#include <opa/scriptmanager.h>
#include <opa/module.h>
#include <opa/virtualobj.h>

#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_pair;
using std::make_shared;

using opa::VirtualObj;
using opa::ScriptManager;
using opa::Module;

using opa::lua::LuaMachine;
using opa::lua::State;
using opa::lua::wrap::Function;
using opa::lua::wrap::ModuleInfo;
using opa::lua::wrap::VariableGetter;

namespace {

const string LOGMARK = "[--LOG--] ";

int add (int x, int y) {
  return x+y;
}

void hello () {
  cout << "Hello!" << endl;
}

int variable = 42;
string name = "Bob";
struct A {} object;

int luaopen_native (lua_State* L_);

ModuleInfo::FunctionList functions = {
    make_shared<Function<int (int, int)>>("add",add),
    make_shared<Function<void (void)>>("hello",hello)
};

ModuleInfo::FunctionList getters = {
    make_shared<VariableGetter<int>>("variable", &variable),
    make_shared<VariableGetter<string>>("name", &name),
    make_shared<VariableGetter<A>>("object", &object)
};

ModuleInfo info(
    "native", luaopen_native,
    {
        {"getters",getters}, {"setters",{}}, {"functions",functions},
        {"member_getters",{}},
        {"member_setters",{}},
        {"member_functions",{}}
    },
    {}
); 

#define ENTRY(func) make_pair(string(#func), (func))

int luaopen_native (lua_State* L) {
    return ExportModule(L, &info);
};

void InitScripts () {
    LuaMachine *vm = new LuaMachine;
    SCRIPT_MANAGER()->Register(vm);
    vm->RegisterModule(Module<int(*)(lua_State*)>("native", luaopen_native));
    SCRIPT_MANAGER()->Initialize("./scripts/");
}

bool RunSample (const string& which) try {
    VirtualObj sample = SCRIPT_MANAGER()->LoadModule(which+"sample");
    if (!sample) return false;
    if (!sample["main"]) return false;
    VirtualObj::List args;
    VirtualObj result = sample["main"](args);
    if (!result) return false;
    return result.value<bool>();
} catch (std::runtime_error& e) {
    cout << e.what() << endl;
    return false;
}

} // unnamed namespace

int main(int argc, char **argv) {
    int success = EXIT_SUCCESS;
    InitScripts();
    
    if(!RunSample("lua")) {
        cout << LOGMARK << "Lua failed!" << endl;
        success = EXIT_FAILURE;
    } else
        cout << LOGMARK << "Lua was successful!" << endl;

    SCRIPT_MANAGER()->Finalize();
    delete SCRIPT_MANAGER();
    
    return success;
}
