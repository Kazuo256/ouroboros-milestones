
#include <languages/lua/luamachine.h>
#include <languages/lua/converter.h>
#include <languages/lua/header.h>
#include <languages/lua/wrap/function.h>

#include <opa/script.h>
#include <opa/scriptmanager.h>
#include <opa/module.h>
#include <opa/virtualobj.h>

#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;

using opa::VirtualObj;
using opa::ScriptManager;
using opa::Module;

using opa::lua::LuaMachine;
using opa::lua::State;

namespace {

const string LOGMARK = "[--LOG--] ";

int add (int x, int y) {
  return x+y;
}

void hello () {
  cout << "Hello!" << endl;
}

int luaopen_native (lua_State* L_) {
  State L(L_);
  L.settop(0);
  L.newtable();
  opa::lua::wrap::PushNativeFunction(L, add);
  L.setfield(1, "add");
  opa::lua::wrap::PushNativeFunction(L, hello);
  L.setfield(1, "hello");
  return 1;
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
