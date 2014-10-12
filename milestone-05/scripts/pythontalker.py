#!/usr/bin/python
# -*- coding: UTF-8 -*-    

from milestone_05_prompt.input import Receiver
import milestone_05_prompt as prompt

def main():
    rec = Receiver()
    out = prompt.out.Sender()

    out.SendMessage("WAZAAAAAAAAAP")
    while True:
        msg = rec.ReceiveMessage()
        print "message received = [%s]" % (msg)
        if msg in ["adios", "adieu", "arrivederci", "quit", "goodbye", "flw", "falou", "té mais", "té", "bye", "hasta"]:
            break

        elif msg == "hip hip":
            out.SendMultimessage("HOORAH!", 3)

        elif msg in ["vegeta", "scouter", "nappa"]:
            out.SendMessage("what was Goku's power level reported from Vegeta's scouter?")
            pl = rec.ReceiveNumber()
            if pl > 9000.0:
                out.SendMessage("correct.")
            else:
                out.SendMessage("dafuq dude?")

        elif msg == "ask me":
            out.SendMessage("vc é bobo?")
            bobo = rec.ReceiveConfirmation()
            out.SendMessage(str(bobo)+"? Hmpf.")

        elif msg == "break":
            out.break_line = not out.break_line
            out.SendMessage("toggled break line - "+str(out.break_line))

        elif msg == "info around":
            out.SendMessage("type in the info...")
            inf = rec.ReceiveInfo()
            out.SendMessage("receiving and sending info...")
            out.SendInfo(inf)
        elif msg == "get info":
            out.SendMessage("type in the info...")
            inf = rec.ReceiveInfo()
            out.SendMessage( "Got info = subject:%s | predicate:%s | object:%s "%(inf.subject(), inf.predicate(), inf.object()) )
        elif msg == "send info":
            out.SendMessage("Type the info attributes in a row: 'subject', 'predicate' and 'object'.")
            s = rec.ReceiveMessage()
            p = rec.ReceiveMessage()
            o = rec.ReceiveMessage()
            inf = prompt.Info()
            inf.set_subject(s)
            inf.set_predicate(p)
            inf.set_object(o)
            out.SendMessage("Sending info...")
            out.SendInfo(inf)

        elif msg in ["help", "h"]:
            out.SendMessage(" 'hip hip', 'scouter', 'ask me', 'break', 'info around', 'get info', 'send info', 'quit'")
        
    return True
