// in /home/suzy/nwjs/src/third_party/blink/renderer/bindings/core/v8/local_window_proxy.h
void LocalWindowProxy::updateTaintTrackingContextId()

// in /home/suzy/nwjs/src/third_party/blink/renderer/bindings/core/v8/script_controller.cc
void ScriptController::updateTaintTrackingContextId() {

// ScriptState holds all information about script execution 
// (e.g., v8::Isolate, v8::Context, DOMWrapperWorld, ExecutionContext etc)

// ScriptState is in a 1:1 relationship with v8::Context.


// ../../v8/src/strings/string-builder-inl.h:208:24: error: no matching function for call to 'GetWriteableStringTaintData'
//         start_taint_ = tainttracking::GetWriteableStringTaintData(
//                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ../../v8/src/taint_tracking.h:264:31: note: candidate template ignored: could not match 'T *' against 'v8::internal::SeqTwoByteString'
// template <class T> TaintData* GetWriteableStringTaintData(T* str);
//                               ^


// ../../v8/src/strings/string-builder-inl.h:327:5: error: no matching function for call to 'SetTaintStatus'



// definition of template functions wrong



void CodeAssembler::StoreNoWriteBarrier(MachineRepresentation rep, Node* base,
                                        Node* offset, Node* value)
// to AddNode to schedule

// The RawMachineAssembler produces a low-level IR graph.
// Also note that the generated graph is only valid together with the generated
// schedule,

// A schedule represents the result of assigning nodes to basic blocks
// and ordering them within basic blocks.
