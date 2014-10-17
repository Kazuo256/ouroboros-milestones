
local native = require 'native'

function main ()
  native.hello()
  print (native.add(10, 23))
  print (native.variable)
  print (native.name)
  print (native.object)
  return true
end

