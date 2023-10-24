# pilot-ios-spm

pilot-ios-spm

# Documentation for integrating sPilot with AvPlayer

## 1. Add a package dependency

### 1.1. Using Swift Package Manager

- Select `File` → `Swift Package` → `Add Package Dependency`
- Enter package dependency url: `https://github.com/piltekvn/pilot-ios-spm.git`
- Select `Next`
- Select `Version` -> Select `Exact` -> Input `X.X.X` (version you want to install, example 1.0.1)
- Select `Done`

### 1.2. Using CocoaPods

#### 1.2.1. Add library in Podfile:

`pod 'pilot-ios-sdk', :git => 'https://github.com/piltekvn/pilot-ios-sdk.git'`

#### 1.2.2. Create Objective-C bridging header to expose file to Swift [See detail](https://developer.apple.com/documentation/swift/importing-objective-c-into-swift)

**Example:**

- Select `New file` → `Header file` → Enter `OTT-Bridging-Header.h`
- In the `Build Settings` → search for `Objective-C Bridging Header` → Enter path to `OTT-Bridging-Header.h` just created above
- In the `OTT-Bridging-Header.h` enter `#import <pilot-ios-sdk/OTT.h>`

## 2. Project configuration

- **Add library**
  - `libc++.tbd`
  - `AVFoundation.framework`
- In the **Build Settings**, set **Enable Bitcode = NO**

## 3. Initialize pilot in Project

```swift
// If you use CocoaPods, remove the line below
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
let originUrl = ""
let pilotUrl = OTT.getInstance().generate(originUrl, configKey: "PROPERTY_ID")

// Transfer Pilot File to AvPlayer
```

including:

- PROPERTY_ID: Will take from sPilot's CMS system.
  ![Get Property Id from CMS](./assets/property_id.png 'Property Id')
