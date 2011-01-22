#
#   PreferencesController.py
#
#   Created by Jair Gaxiola on 15/01/11.
#   Copyright 2011 __MyCompanyName__. All rights reserved.
#

from Foundation import *
from AppKit import *

import objc

class PreferencesController (NSWindowController):
	start = objc.IBOutlet()
	stop = objc.IBOutlet()
	open = objc.IBOutlet()
	nginxPort = objc.IBOutlet()
	mysqlPort = objc.IBOutlet()
	phpPort = objc.IBOutlet()

	def init(self):
		self.initWithWindowNibName_("Preferences")
		return self
	
	def windowDidLoad(self):
		self.setSettings()

	def show(self):
		#print dir(self.preferencesController)
		#if self.preferencesController == None:
		self.preferencesController = PreferencesController.alloc().init()
		self.preferencesController.showWindow_(self)
		#self.PreferencesController.window().makeKeyAndOrderFront_(self)
	#	self.PreferencesController = PreferencesController.alloc().initWithNibName_bundle_("Preferences", None)
	#	self.PreferencesController.view().window().makeKeyAndOrderFront_(self)
		#print dir(self.PreferencesController)
		#print dir(self.preferencesController.start)
	#	self.setSettings(self.start, "start")
		#return self.preferencesController
		#pass
	show = classmethod(show)
	
	def setSettings(self):
		settings = NSUserDefaults.standardUserDefaults()
		#print "SET SETTINGSS"
		#print dir(settings)
		startMEMP = settings.boolForKey_("start")
		stopMEMP = settings.boolForKey_("stop")
		openMEMP = settings.boolForKey_("open")
		nginxPort = settings.stringForKey_("nginxPort")
		mysqlPort = settings.stringForKey_("mysqlPort")
		phpPort = settings.stringForKey_("phpPort")
		print startMEMP
		#print dir(self.start)
		if startMEMP:
			self.start.setState_(NSOnState)
		else:
			self.start.setState_(NSOffState)

		if stopMEMP:
			self.stop.setState_(NSOnState)
		else:
			self.stop.setState_(NSOffState)
			
		if openMEMP:
			self.open.setState_(NSOnState)
		else:
			self.open.setState_(NSOffState)
		
		if nginxPort:
			self.nginxPort.setStringValue_(nginxPort)

		if mysqlPort:
			self.mysqlPort.setStringValue_(mysqlPort)
		
		if phpPort:
			self.phpPort.setStringValue_(phpPort)
			
	@objc.IBAction
	def savePreferences_(self, sender):
		settings = NSUserDefaults.standardUserDefaults()
		
		if self.start.state():
			print "On"
			settings.setObject_forKey_(1, 'start')
		else:
			print "Off"
			settings.setObject_forKey_(0, 'start')
		
		if self.stop.state():
			print "On"
			settings.setObject_forKey_(1, 'stop')
		else:
			print "Off"
			settings.setObject_forKey_(0, 'stop')
		
		if self.open.state():
			print "On"
			settings.setObject_forKey_(1, 'open')
		else:
			print "Off"
			settings.setObject_forKey_(0, 'open')
		print dir(self.nginxPort)
		if self.nginxPort.stringValue():
			print "On nginx"
			settings.setObject_forKey_(self.nginxPort.stringValue(), 'nginxPort')
		else:
			print "Off"
			settings.setObject_forKey_("80", 'nginxPort')
		
		if self.mysqlPort.stringValue():
			print "On"
			settings.setObject_forKey_(self.mysqlPort.stringValue(), 'mysqlPort')
		else:
			print "Off"
			settings.setObject_forKey_("3306", 'mysqlPort')
		
		if self.phpPort.stringValue():
			print "On"
			settings.setObject_forKey_(self.phpPort.stringValue(), 'phpPort')
		else:
			print "Off"
			settings.setObject_forKey_("9000", 'phpPort')
		
		settings.synchronize()
		

