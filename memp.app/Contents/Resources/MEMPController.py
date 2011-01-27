#
#   MEMPController.py
#
#   Created by Jair Gaxiola on 06/01/11.
#   Copyright 2011 __MyCompanyName__. All rights reserved.
#

from Foundation import *
from AppKit import *
from Authorization import Authorization, kAuthorizationFlagDestroyRights
from PreferencesController import PreferencesController

import objc
import os


class MEMPController (NSWindowController):
    startButton = objc.IBOutlet()
    stopButton = objc.IBOutlet()
    startNginx = objc.IBOutlet()
    stopNginx = objc.IBOutlet()
    startMySQL = objc.IBOutlet()
    stopMySQL = objc.IBOutlet()
    startPHP = objc.IBOutlet()
    stopPHP = objc.IBOutlet()
    preferences = objc.IBOutlet()
    window = objc.IBOutlet()
	
    def init(self):
		self = super(MEMPController, self).initWithWindowNibName_("MainMenu")
		if self:
			self.path = "/Applications/MEMP/init/"
			self.auth = Authorization()
		return self
		
    @objc.IBAction
    def startServers_(self, sender):
		self.startButton.setHidden_(YES)
		self.stopButton.setHidden_(NO)
		
		startScript = self.path + "start"
		self.auth.executeWithPrivileges(startScript)

		print "start servers..."
		
    @objc.IBAction
    def stopServers_(self, sender):
		self.startButton.setHidden_(NO)
		self.stopButton.setHidden_(YES)

		stopScript = self.path + "stop"
		self.auth.executeWithPrivileges(stopScript)

		print "stop servers"
	
    @objc.IBAction
    def openPage_(self, sender):
		urlMEMP = NSURL.URLWithString_("http://localhost/MEMP/")
		workspace = NSWorkspace.sharedWorkspace().openURL_(urlMEMP)
		print "opan memp page"
	
    @objc.IBAction
    def startNginx_(self, sender):
		self.startNginx.setHidden_(YES)
		self.stopNginx.setHidden_(NO)
		
		startNginx = self.path + "startNginx"
		self.auth.executeWithPrivileges(startNginx)
	
    @objc.IBAction
    def stopNginx_(self, sender):
		self.startNginx.setHidden_(NO)
		self.stopNginx.setHidden_(YES)
		
		stopNginx = self.path + "stopNginx"
		self.auth.executeWithPrivileges(stopNginx)

    @objc.IBAction
    def startMySQL_(self, sender):
		self.startMySQL.setHidden_(YES)
		self.stopMySQL.setHidden_(NO)
		
		startMySQL = self.path + "startMySQL"
		self.auth.executeWithPrivileges(startMySQL)
	
    @objc.IBAction
    def stopMySQL_(self, sender):
		self.startMySQL.setHidden_(NO)
		self.stopMySQL.setHidden_(YES)

		stopMySQL = self.path + "stopMySQL"
		self.auth.executeWithPrivileges(stopMySQL)

			
    @objc.IBAction
    def startPHP_(self, sender):
		self.startPHP.setHidden_(YES)
		self.stopPHP.setHidden_(NO)
		
		startPHP = self.path + "startPHP"
		self.auth.executeWithPrivileges(startPHP)
	
    @objc.IBAction
    def stopPHP_(self, sender):
		self.startPHP.setHidden_(NO)
		self.stopPHP.setHidden_(YES)

		stopPHP = self.path + "stopPHP"
		self.auth.executeWithPrivileges(stopPHP)

    @objc.IBAction
    def preferences_(self, sender):
		PreferencesController.show()
	
    @objc.IBAction
    def showPreferencesWindow_(self, sender):
		self.preferencesController = PreferencesController.alloc().init()
		self.preferencesController.showWindow_(self)

    @objc.IBAction
    def exit_(self, sender):
		self.stopServers_(self)
		NSApp().terminate_(self)

    def checkSettings(self):
		settings = NSUserDefaults.standardUserDefaults()

		startMEMP = settings.boolForKey_("start")
		if startMEMP:
			try:
				self.startServers_(self)
			except:
				pass
		
		openMEMP = settings.boolForKey_("open")
		if openMEMP:
			self.startServers_(self)
			self.openPage_(self)