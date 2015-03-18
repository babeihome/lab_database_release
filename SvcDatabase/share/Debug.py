#! /usr/bin/python
#-------------------------------------------------------------------
import os
import DMPSW                    # Load DAMPE software
import libDmpSvcDatabase as DmpDB

#-------------------------------------------------------------------
# Global setting
#DMPSW.Core.SetEventNumber(40)     # default: -1
#DMPSW.Core.SetStartTime("2014-11-17 13:37:20")     # default: 2013-01-01 00:00:00
#DMPSW.Core.SetStopTime("2014-11-17 13:39:30")      # default: 2053-01-01 00:00:00
#DMPSW.Core.LogLevel("Debug")      # Value = {Error | Warning | Info | Debug}. default: Info.
#DMPSW.Core.LogHeader("On") # default: off

#-------------------------------------------------------------------
# RootIOSvc options
#DMPSW.RootIOSvc.InputPath(os.environ["DMPSWWORK"]+"/data/sci")
#inputFileName = "./A2Data00_20141118_163049.root"
#DMPSW.RootIOSvc.SetInputFile(inputFileName)
#DMPSW.RootIOSvc.OutputFile("./DmpCalBgoMip.root")
#DMPSW.RootIOSvc.SetWriteList("Event/Rec0")  # split by ;
#DMPSW.RootIOSvc.OutputPath(os.environ["DMPSWWORK"]+"/run/data/cal/ped")

#-------------------------------------------------------------------
# Creat user's service or algorithm
db = DmpDB.DmpSvcDatabase()
DMPSW.SvcMgr.Append(db)

#-------------------------------------------------------------------
# Run job
DMPSW.Core.Initialize()
#DMPSW.Core.Run()
DMPSW.Core.Finalize()

