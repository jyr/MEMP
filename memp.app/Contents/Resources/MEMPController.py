#
#   MEMPController.py
#
#   Created by Jair Gaxiola on 01/01/11.
#   Copyright 2011 __MyCompanyName__. All rights reserved.
#

from Foundation import *
from AppKit import *
import objc
import os
#from Authorization import Authorization
#from SecurityFoundation import SFAuthorization as Authorization

class MEMPController(NSWindowController):
	
	def init(self):
		self = super(MEMPController, self).init()
		self.path = "sh /Applications/MEMP/init/"
		#print dir(Authorization)
		#self.authorizationRef = authorizationRef()
		return self
		
	@objc.IBAction
	def startServers_(self, sender):
		#status = Authorization
		os.system(self.path + "start.sh")
		print "start servers..."
	
	@objc.IBAction
	def stopServers_(self, sender):
		os.system(self.path + "stop.sh")
		print "stop servers"
	
	@objc.IBAction
	def openPage_(self, sender):
		print "opan memp page"
	
	@objc.IBAction
	def exit_(self, sender):
		self.stopServers_(self)
		NSApp().terminate_(self)



