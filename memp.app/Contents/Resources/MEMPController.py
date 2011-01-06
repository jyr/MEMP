#
#   MEMPController.py
#
#   Created by Jair Gaxiola on 06/01/11.
#   Copyright 2011 __MyCompanyName__. All rights reserved.
#

from Foundation import *
from AppKit import *
import objc
import os

class MEMPController (NSWindowController):
    startButton = objc.IBOutlet()
    stopButton = objc.IBOutlet()
	
    def init(self):
		self = super(MEMPController, self).init()
		self.path = "sh /Applications/MEMP/init/"
		return self
		
    @objc.IBAction
    def startServers_(self, sender):
		#status = Authorization
		os.system(self.path + "start.sh")
		self.startButton.setHidden_(YES)
		self.stopButton.setHidden_(NO)
		print "start servers..."
	
    @objc.IBAction
    def stopServers_(self, sender):
		os.system(self.path + "stop.sh")
		self.startButton.setHidden_(NO)
		self.stopButton.setHidden_(YES)
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
