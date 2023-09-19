// Most object types in the V8 JavaScript are described in this file.
//
// Inheritance hierarchy:
// - Object
//   - Smi          (immediate small integer)
//   - HeapObject   (superclass for everything allocated in the heap)
//     - JSReceiver  (suitable for property access)
//       - JSObject
//         - JSArray
//         - JSArrayBuffer
//         - JSArrayBufferView
//           - JSTypedArray
//           - JSDataView
//         - JSBoundFunction
//         - JSCollection
//           - JSSet
//           - JSMap
//         - JSSetIterator
//         - JSMapIterator
//         - JSWeakCollection
//           - JSWeakMap
//           - JSWeakSet
//         - JSRegExp
//         - JSFunction
//         - JSGeneratorObject
//         - JSGlobalObject
//         - JSGlobalProxy
//         - JSValue
//           - JSDate
//         - JSMessageObject
//       - JSProxy
//     - FixedArrayBase
//       - ByteArray
//       - BytecodeArray
//       - FixedArray
//         - DescriptorArray
//         - LiteralsArray
//         - HashTable
//           - Dictionary
//           - StringTable
//           - StringSet
//           - CompilationCacheTable
//           - CodeCacheHashTable
//           - MapCache
//         - OrderedHashTable
//           - OrderedHashSet
//           - OrderedHashMap
//         - Context
//         - TypeFeedbackMetadata
//         - TypeFeedbackVector
//         - TemplateList
//         - TransitionArray
//         - ScopeInfo
//         - ScriptContextTable
//         - WeakFixedArray
//       - FixedDoubleArray
//     - Name
//       - String
//         - SeqString
//           - SeqOneByteString
//           - SeqTwoByteString
//         - SlicedString
//         - ConsString
//         - ExternalString
//           - ExternalOneByteString
//           - ExternalTwoByteString
//         - InternalizedString
//           - SeqInternalizedString
//             - SeqOneByteInternalizedString
//             - SeqTwoByteInternalizedString
//           - ConsInternalizedString
//           - ExternalInternalizedString
//             - ExternalOneByteInternalizedString
//             - ExternalTwoByteInternalizedString
//       - Symbol
//     - HeapNumber
//     - Simd128Value
//       - Float32x4
//       - Int32x4
//       - Uint32x4
//       - Bool32x4
//       - Int16x8
//       - Uint16x8
//       - Bool16x8
//       - Int8x16
//       - Uint8x16
//       - Bool8x16
//     - Cell
//     - PropertyCell
//     - Code
//     - AbstractCode, a wrapper around Code or BytecodeArray
//     - Map
//     - Oddball
//     - Foreign
//     - SharedFunctionInfo
//     - Struct
//       - Box
//       - AccessorInfo
//       - AccessorPair
//       - AccessCheckInfo
//       - InterceptorInfo
//       - CallHandlerInfo
//       - TemplateInfo
//         - FunctionTemplateInfo
//         - ObjectTemplateInfo
//       - Script
//       - DebugInfo
//       - BreakPointInfo
//       - CodeCache
//       - PrototypeInfo
//     - WeakCell
//
// Formats of Object*:
//  Smi:        [31 bit signed int] 0
//  HeapObject: [32 bit direct pointer] (4 byte aligned) | 01



// The AST refers to variables via VariableProxies - placeholders for the actual
// variables. Variables themselves are never directly referred to from the AST,
// they are maintained by scopes, and referred to from VariableProxies and Slots
// after binding and variable allocation.


how to find the proxy if we know the variable?


// Global invariants after AST construction: Each reference (i.e. identifier)
// to a JavaScript variable (including global properties) is represented by a
// VariableProxy node. Immediately after AST construction and before variable
// allocation, most VariableProxy nodes are "unresolved", i.e. not bound to a
// corresponding variable (though some are bound during parse time). Variable
// allocation binds each unresolved VariableProxy to one Variable and assigns
// a location. Note that many VariableProxy nodes may refer to the same Java-
// Script variable.


// The Zone supports very fast allocation of small chunks of
// memory. The chunks cannot be deallocated individually, but instead
// the Zone supports deallocating all chunks in one fast
// operation. The Zone is used to hold temporary data structures like
// the abstract syntax tree, which is deallocated after compilation.


// An Isolate is an independant copy of the V8 runtime which includes its own heap. 
// Two different Isolates can run in parallel and can be seen as entirely different sandboxed 
// instances of a V8 runtime.



// To allow separate JavaScript applications to run in the same isolate a context 
// must be specified for each one. This is to avoid them interfering with each other, 
// for example by changing the builtin objects provided.



VariableProxy* proxy = property->key()->AsVariableProxy()


BuildVariableLoad and BuildVariableLoadForAccumulatorValue in 
v8/src/interpreter/bytecode-generator.cc



or you can GenerateTaintTrackingHook(expr);
directly


node_serializer_ I don't know how to get it for now