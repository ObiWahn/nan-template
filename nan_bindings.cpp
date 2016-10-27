#include <nan.h>
#include "library.hpp"

using namespace v8;

#define NAN_TEST_GOOD_SYLE

//// define a function
#define NAN_TEST_GOOD_SYLE
NAN_METHOD(hello) {
    info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}
#else // use internals
// Nan::NAN_METHOD_RETURN_TYPE hello(Nan::NAN_METHOD_ARGS_TYPE info)
void hello(const Nan::FunctionCallbackInfo<v8::Value>& info){
    info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}
#endif

//// populate exports like object (called target)
#if defined(NAN_TEST_GOOD_STYLE)
NAN_MODULE_INIT(Init){
    //target is created by the macro
    NAN_EXPORT(target, hello);
    Nan::Export(target, "hello2", hello); //export with a different name
}

#else // use internals
//void Init(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target){
void Init(v8::Local<v8::Object> target){
    Nan::Set(target
            ,Nan::New<v8::String>("hello").ToLocalChecked()
            ,Nan::GetFunction(Nan::New<v8::FunctionTemplate>(hello)).ToLocalChecked()
            );
}
#endif

//// tell node that the nan_bindings module will be initialized with the Init function
NODE_MODULE(nan_bindings, Init)
