
local native = require 'native'

function main ()
  native.hello()
  print (native.add(10, 23))
  print ('variable before: ', native.variable)
  native.variable = 57
  print ('variable after: ', native.variable)
  print ('name before: ', native.name)
  native.name = "Dude"
  print ('name after: ', native.name)
  print (native.object)
  return true
end

