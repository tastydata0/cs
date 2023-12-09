{ pkgs }: {
	deps = [
        pkgs.mlocate
        pkgs.cmake
        pkgs.clang_12
        pkgs.ccls
        pkgs.gdb
        pkgs.gnumake
        pkgs.openssl
        pkgs.mbedtls
	];
}