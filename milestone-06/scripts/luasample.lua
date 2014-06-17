
local native = require 'native'

function main ()
  native.hello()
  print (native.add(10, 23))
  return true
end

