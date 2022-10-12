const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("hello", "src/main.zig");
    exe.strip = true;
    exe.single_threaded = true;
    exe.pie = false;
    exe.want_lto = true;
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();
}
