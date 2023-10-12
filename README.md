# pilot-ios-spm

pilot-ios-spm

# Documentation for integrating sPilot with AvPlayer

## 1. Add a package dependency

- Select `File` -> `Swift Package` -> `Add Package Dependency`
- Enter package dependency url: `https://github.com/piltekvn/pilot-ios-spm.git`
- Select `Next` -> Branch `main` -> `Next`

## 2. Project configuration

- **Add library** - libc++.tbd - AVFoundation.framework
- In **Build Settings**, set **Enable Bitcode = NO**
- **Enable protocol calling HTTP và local resource**

In Xcode's Project Navigator, open the Info.plist file in source edit mode. And add one of the values below.

```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

OR

```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsLocalNetworking</key>
    <true/>
</dict>
```

## 3. Initialize pilot in Project

```swift
// Import pilot SDK
import PilotFramework
... // Other sources
override func viewDidLoad() {
		super.viewDidLoad()
		OTT.getInstance().initialize("PARTNER_ID")
}
```

including:

- PARTNER_ID: Taken from sPilot's CMS system
  ![Get Partner Id from CMS](./assets/partner_id.png 'Partner Id')

## 4. Create a new url for each channel according to the corresponding property.

```swift
// Original media link
let *originUrl = @"";
let pilotUrl = OTT.getInstance().generate(originUrl, configKey: "PROPERTY_ID")

// Transfer Pilot File to AvPlayer
```

including:

- PROPERTY_ID: Will take from sPilot's CMS system.
  ![Get Property Id from CMS](./assets/property_id.png 'Property Id')
