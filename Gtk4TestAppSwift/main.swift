//
//  main.swift
//  Gtk4SwiftTestApp
//
//  Created 01/12/2021.
//

import Foundation
import Gtk4TestAppC

var buttonContent = "Proc: \(ProcessInfo.processInfo.processName), OS: \(ProcessInfo.processInfo.operatingSystemVersionString)"

buttonContent.withCString { ptr in
    let mutablePtr:UnsafeMutablePointer<Int8> = UnsafeMutablePointer.init(mutating: ptr)
    var argv: [UnsafeMutablePointer<Int8>?] = [mutablePtr]
    main_c(1, &argv)
}

