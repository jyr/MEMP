#
#   MEMPController.py
#
#   Created by Jair Gaxiola on 06/01/11.
#   Copyright 2011 __MyCompanyName__. All rights reserved.
#

from Foundation import *
from AppKit import *
from Authorization import Authorization, kAuthorizationFlagDestroyRights
import objc
import os

class MEMPController (NSWindowController):
    startButton = objc.IBOutlet()
    stopButton = objc.IBOutlet()
	
    def init(self):
		self = super(MEMPController, self).init()
		self.path = "/Applications/MEMP/init/"
		#self.auth = Authorization(destroyflags=(kAuthorizationFlagDestroyRights),)
		self.auth = Authorization()
		return self
		
    @objc.IBAction
    def startServers_(self, sender):
		self.startButton.setHidden_(YES)
		self.stopButton.setHidden_(NO)

		
		startScript = self.path + "start"
		self.auth.executeWithPrivileges(startScript)
		#os.system("sh " + self.path + "mysql.sh start")
		#os.system(privileges)
		print "start servers..."
	
    @objc.IBAction
    def stopServers_(self, sender):
		self.startButton.setHidden_(NO)
		self.stopButton.setHidden_(YES)

		stopScript = self.path + "stop"
		self.auth.executeWithPrivileges(stopScript)
		#os.system("sh " + self.path + "mysql.sh stop")
		#os.system(privileges)
		print "stop servers"
	
    @objc.IBAction
    def openPage_(self, sender):
		urlMEMP = NSURL.URLWithString_("http://localhost")
		workspace = NSWorkspace.sharedWorkspace().openURL_(urlMEMP)
		print "opan memp page"
	
    @objc.IBAction
    def exit_(self, sender):
		self.stopServers_(self)
		NSApp().terminate_(self)
