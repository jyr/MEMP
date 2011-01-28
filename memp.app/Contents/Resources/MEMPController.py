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
		try:
			startScript = self.path + "start"
			self.auth.executeWithPrivileges(startScript)
			self.startButton.setHidden_(YES)
			self.stopButton.setHidden_(NO)
		except:
			pass
		
    @objc.IBAction
    def stopServers_(self, sender):
		try:
			stopScript = self.path + "stop"
			self.auth.executeWithPrivileges(stopScript)
			self.startButton.setHidden_(NO)
			self.stopButton.setHidden_(YES)
		except:
			pass
	
    @objc.IBAction
    def openPage_(self, sender):
		urlMEMP = NSURL.URLWithString_("http://localhost/MEMP/")
		workspace = NSWorkspace.sharedWorkspace().openURL_(urlMEMP)
	
    @objc.IBAction
    def startNginx_(self, sender):
		try:
			startNginx = self.path + "startNginx"
			self.auth.executeWithPrivileges(startNginx)
			self.startNginx.setHidden_(YES)
			self.stopNginx.setHidden_(NO)
		except:
			pass
	
    @objc.IBAction
    def stopNginx_(self, sender):
		try:		
			stopNginx = self.path + "stopNginx"
			self.auth.executeWithPrivileges(stopNginx)
			self.startNginx.setHidden_(NO)
			self.stopNginx.setHidden_(YES)
		except:
			pass

    @objc.IBAction
    def startMySQL_(self, sender):
		try:
			startMySQL = self.path + "startMySQL"
			self.auth.executeWithPrivileges(startMySQL)
			self.startMySQL.setHidden_(YES)
			self.stopMySQL.setHidden_(NO)
		except:
			pass
	
    @objc.IBAction
    def stopMySQL_(self, sender):
		try:
			stopMySQL = self.path + "stopMySQL"
			self.auth.executeWithPrivileges(stopMySQL)
			self.startMySQL.setHidden_(NO)
			self.stopMySQL.setHidden_(YES)
		except:
			pass

			
    @objc.IBAction
    def startPHP_(self, sender):
		try:		
			startPHP = self.path + "startPHP"
			self.auth.executeWithPrivileges(startPHP)
			self.startPHP.setHidden_(YES)
			self.stopPHP.setHidden_(NO)
		except:
			pass
	
    @objc.IBAction
    def stopPHP_(self, sender):
		try:
			stopPHP = self.path + "stopPHP"
			self.auth.executeWithPrivileges(stopPHP)
			self.startPHP.setHidden_(NO)
			self.stopPHP.setHidden_(YES)
		except:
			pass

    @objc.IBAction
    def preferences_(self, sender):
		PreferencesController.show()
	
    @objc.IBAction
    def showPreferencesWindow_(self, sender):
		self.preferencesController = PreferencesController.alloc().init()
		self.preferencesController.showWindow_(self)

    @objc.IBAction
    def exit_(self, sender):
		settings = NSUserDefaults.standardUserDefaults()
		stopMEMP = settings.boolForKey_("stop")
		
		if stopMEMP:
			self.stopServers_(self)

		NSApp().terminate_(self)

    def checkSettings(self):
		settings = NSUserDefaults.standardUserDefaults()

		startMEMP = settings.boolForKey_("start")
		if startMEMP:
			self.startServers_(self)
		
		openMEMP = settings.boolForKey_("open")
		if openMEMP:
			self.startServers_(self)