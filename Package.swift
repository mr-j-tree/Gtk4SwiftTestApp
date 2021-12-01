// swift-tools-version:5.5
//
//  Package.swift
//  Gtk4SwiftTestApp
//
//  Created 01/12/2021.
//
import PackageDescription

let package = Package(
    name: "Gtk4TestApp",
    platforms: [.macOS(.v12)],
    products: [
        .library(
            name: "Gtk4TestApp",
            targets: ["Gtk4TestAppSwift", "Gtk4TestAppC"]),
    ],
    dependencies: [],
    targets: [
        .systemLibrary(
            name: "CGtk",
            path: "CGtk",
            pkgConfig: "gtk4",
            providers: [
                .brew(["gtk4", "glib", "glib-networking"/*, "gobject-introspection"*/]),
                .apt(["libgtk-4-dev", "libglib2.0-dev", "glib-networking"/*, "gobject-introspection", "libgirepository1.0-dev"*/])
            ]
        ),
        .target(
            name: "Gtk4TestAppC",
            dependencies: ["CGtk"],
            path: "Gtk4TestAppC",
            publicHeadersPath: "publicHeaders"

        ),
        .executableTarget(name: "Gtk4TestAppSwift", dependencies: ["Gtk4TestAppC"], path: "Gtk4TestAppSwift")
    ]
)
