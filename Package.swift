// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "PilotIOS",
    platforms: [.iOS(.v9)],
    products: [
        .library(
            name: "PilotIOS",
            targets: ["PilotIOS", "PilotFramework"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "PilotFramework",
            path: "xcframeworks/PilotCDN.xcframework"
        ),
        .target(
            name: "PilotIOS"
        ),
    ]
)
