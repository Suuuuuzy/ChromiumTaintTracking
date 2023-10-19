alias run_chrome_test='sudo ~/chromium/src/out/chrome/chrome http://127.0.0.1:8000/index.html?color=alert(1) --js-flags="--taint_log_file=/home/suzy/temp/taint_log_file/log0 --no-crankshaft --no-turbo --no-ignition" --new-window --user-data-dir=/home/suzy/temp/jianjia_test --no-sandbox --disable-hang-monitor --disable-gpu &> /home/suzy/temp/jianjia_std_out'
alias decode_capnp='/home/suzy/Documents/capnproto-install-clang-chrome decode /home/suzy/chromium/src/v8/src/taint_tracking/protos/logrecord.capnp TaintLogRecord <'


alias run_chrome_bytecode='sudo ~/chromium/src/out/chrome/chrome http://127.0.0.1:8000/index.html?color=alert(1) --js-flags="--print-bytecode --taint_log_file=/home/suzy/temp/taint_log_file/log0 --no-crankshaft --no-turbo --no-ignition" --new-window --user-data-dir=/home/suzy/temp/jianjia_test --no-sandbox --disable-hang-monitor --disable-gpu &> /home/suzy/temp/jianjia_std_out'
