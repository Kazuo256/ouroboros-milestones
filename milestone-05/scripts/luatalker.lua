
local out     = require 'prompt.out'
local input   = require 'prompt.input'
local prompt  = require 'prompt'

local function nogetter ()
  local test = input.Receiver()
  local check, err = pcall(function () assert(test.sbrubles) end)
  if check == false and err then
    print(err)
  else
    return false
  end
  return true
end

local function nosetter ()
  local test = out.Sender()
  local check, err = pcall(function () test.sbrubles = 42 end)
  if check == false and err then
    print(err)
  else
    return false
  end
  return true
end

function main ()
  local send = out.Sender()
  local receive = input.Receiver()
  local info = prompt.Info()
  info:set_subject "It"
  info:set_predicate "doesn't"
  info:set_object "matter"
  send:SendMessage("Let's check some things first...")
  if not nogetter() or not nosetter() then
    return false
  end
  send:SendMessage("Everything ok so far. S'up bro.", 'unused');
  send:SendMessage("Line breakage status is "..tostring(send.break_line), 'unused');
  while true do
    local msg = receive:ReceiveMessage()
    print("[received '"..msg.."']")
    if msg == "bye" then return true end
    if msg == "dude" then
      send:SendMultimessage("Say what?", 5)
    elseif msg == "sqrt" then
      send:SendMessage("Of...?")
      local arg = receive:ReceiveNumber()
      send:SendMessage("'Tis "..math.sqrt(arg))
    elseif msg == "My favorite color is blue." then
      send.break_line = false
      send:SendMessage("You sure? ")
      send.break_line = true
      local answer = receive:ReceiveConfirmation()
      if answer then
        send:SendMessage("Lame.")
      else
        send:SendMessage("Indecisive fella.")
      end
    elseif msg == "Learn info" then
      send:SendMessage "What info?"
      info = receive:ReceiveInfo()
      send:SendMessage "Ok!"
    elseif msg == "Tell info" then
      send:SendMessage "Here's what I know:"
      send:SendInfo(info)
    end
  end
end

