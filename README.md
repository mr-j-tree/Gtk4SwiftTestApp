# Gtk4SwiftTestApp
A skeleton SwiftPM GUI application using GTK4 on Linux and macOS.

Tested on:

* macOS 12.0.1 / Swift 5.5
* Ubuntu Desktop 21.10 / Raspberry Pi 4 / Swift 5.5 (ARM binary from http://swiftlang.xyz)

Should already work on any system that has apt as package provider, pkg-config for GTK path discovery and Swift 5.5. Other systems could easily be added by adding more SystemPackageProviders in Package.swift, so feel free to submit a PR if you successfully test it on another system.

No GTK functions are exposed to Swift... you can add function signatures or #includes to gtk_bridging.h if you need. All GTK calls are done in C for this example, but the app launches in Swift.

## Instructions

### macOS

Open Package.swift in XCode, wait a moment for everything to load/resolve then run the target called `Gtk4SwiftTestApp`.

### Linux

cd to the folder where you've cloned this repo, and simply do a `swift run`.

## Expected results

If it works, you will get a white window with a single button in the middle, showing the name of the process and the OS version. When you click the button, the app will cleanly exit.

![](screenshot.png)