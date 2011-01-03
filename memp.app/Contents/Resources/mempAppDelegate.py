#
#  mempAppDelegate.py
#  memp
#
#  Created by Jair Gaxiola on 01/01/11.
#  Copyright __MyCompanyName__ 2011. All rights reserved.
#

from Foundation import *
from AppKit import *

class mempAppDelegate(NSObject):
    def applicationDidFinishLaunching_(self, sender):
        NSLog("Application did finish launching.")
