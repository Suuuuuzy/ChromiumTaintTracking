  # export CHROMEDIR="/home/billy/docs/source/chromium_taint_tracking/src";
  export CHROMEDIR="/home/suzy/nwjs/src"

  export SYSROOT="$CHROMEDIR/build/linux/debian_sid_amd64-sysroot"
  export CXX="$CHROMEDIR/third_party/llvm-build/Release+Asserts/bin/clang++";
  export CC="$CHROMEDIR/third_party/llvm-build/Release+Asserts/bin/clang"

  export CXXFLAGS="--sysroot=$SYSROOT -O3 -B$CHROMEDIR/third_party/binutils/Linux_x64/Release/bin -std=c++11 -D_GLIBCXX_USE_CLOCK_REALTIME";

  export LDFLAGS="-B$CHROMEDIR/third_party/binutils/Linux_x64/Release/bin"
  export LDFLAGS="-L$CHROMEDIR/build/linux/debian_sid_amd64-sysroot/lib/x86_64-linux-gnu -Wl,-rpath-link=$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/lib/x86_64-linux-gnu -L$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/usr/lib/x86_64-linux-gnu -Wl,-rpath-link=$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/usr/lib/x86_64-linux-gnu -L$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/usr/lib -Wl,-rpath-link=$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/usr/lib -Wl,-rpath-link=$CHROMEDIR/out/Debug -B$CHROMEDIR/third_party/binutils/Linux_x64/Release/bin -L$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/4.6 -Wl,-rpath-link=$CHROMEDIR/build/linux/debian_wheezy_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/4.6"

  cd c++
  autoreconf -i
  ./configure --with-sysroot="$SYSROOT" --prefix="/home/suzy/Documents/capnproto-install-clang"
  make -j8 check
  sudo make install

export LD_RUN_PATH="$LD_RUN_PATH:$CAPNP_INSTALL/lib"

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'