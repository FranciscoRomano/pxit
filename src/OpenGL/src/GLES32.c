// ---------------------------------------------------------------------------------------------- //
// The MIT License (MIT)
// 
// Copyright (c) 2024 Francisco Romano
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ---------------------------------------------------------------------------------------------- //
#include <GLES32.h>
#ifdef GL_ES_VERSION_3_2

PFN_glBlendBarrier                    glBlendBarrier;
PFN_glCopyImageSubData                glCopyImageSubData;
PFN_glDebugMessageControl             glDebugMessageControl;
PFN_glDebugMessageInsert              glDebugMessageInsert;
PFN_glDebugMessageCallback            glDebugMessageCallback;
PFN_glGetDebugMessageLog              glGetDebugMessageLog;
PFN_glPushDebugGroup                  glPushDebugGroup;
PFN_glPopDebugGroup                   glPopDebugGroup;
PFN_glObjectLabel                     glObjectLabel;
PFN_glGetObjectLabel                  glGetObjectLabel;
PFN_glObjectPtrLabel                  glObjectPtrLabel;
PFN_glGetObjectPtrLabel               glGetObjectPtrLabel;
PFN_glGetPointerv                     glGetPointerv;
PFN_glEnablei                         glEnablei;
PFN_glDisablei                        glDisablei;
PFN_glBlendEquationi                  glBlendEquationi;
PFN_glBlendEquationSeparatei          glBlendEquationSeparatei;
PFN_glBlendFunci                      glBlendFunci;
PFN_glBlendFuncSeparatei              glBlendFuncSeparatei;
PFN_glColorMaski                      glColorMaski;
PFN_glIsEnabledi                      glIsEnabledi;
PFN_glDrawElementsBaseVertex          glDrawElementsBaseVertex;
PFN_glDrawRangeElementsBaseVertex     glDrawRangeElementsBaseVertex;
PFN_glDrawElementsInstancedBaseVertex glDrawElementsInstancedBaseVertex;
PFN_glFramebufferTexture              glFramebufferTexture;
PFN_glPrimitiveBoundingBox            glPrimitiveBoundingBox;
PFN_glGetGraphicsResetStatus          glGetGraphicsResetStatus;
PFN_glReadnPixels                     glReadnPixels;
PFN_glGetnUniformfv                   glGetnUniformfv;
PFN_glGetnUniformiv                   glGetnUniformiv;
PFN_glGetnUniformuiv                  glGetnUniformuiv;
PFN_glMinSampleShading                glMinSampleShading;
PFN_glPatchParameteri                 glPatchParameteri;
PFN_glTexParameterIiv                 glTexParameterIiv;
PFN_glTexParameterIuiv                glTexParameterIuiv;
PFN_glGetTexParameterIiv              glGetTexParameterIiv;
PFN_glGetTexParameterIuiv             glGetTexParameterIuiv;
PFN_glSamplerParameterIiv             glSamplerParameterIiv;
PFN_glSamplerParameterIuiv            glSamplerParameterIuiv;
PFN_glGetSamplerParameterIiv          glGetSamplerParameterIiv;
PFN_glGetSamplerParameterIuiv         glGetSamplerParameterIuiv;
PFN_glTexBuffer                       glTexBuffer;
PFN_glTexBufferRange                  glTexBufferRange;
PFN_glTexStorage3DMultisample         glTexStorage3DMultisample;

int LoadOpenGLES32(void* (*pfnLoadProc)(const char* name))
{
    if (!LoadOpenGLES31(pfnLoadProc)) return 0;

    #define LOAD_OPENGL_PROCEDURE(name)\
    name = (PFN_##name)pfnLoadProc(#name); if (!name) return 0;
    LOAD_OPENGL_PROCEDURE(glBlendBarrier);
    LOAD_OPENGL_PROCEDURE(glCopyImageSubData);
    LOAD_OPENGL_PROCEDURE(glDebugMessageControl);
    LOAD_OPENGL_PROCEDURE(glDebugMessageInsert);
    LOAD_OPENGL_PROCEDURE(glDebugMessageCallback);
    LOAD_OPENGL_PROCEDURE(glGetDebugMessageLog);
    LOAD_OPENGL_PROCEDURE(glPushDebugGroup);
    LOAD_OPENGL_PROCEDURE(glPopDebugGroup);
    LOAD_OPENGL_PROCEDURE(glObjectLabel);
    LOAD_OPENGL_PROCEDURE(glGetObjectLabel);
    LOAD_OPENGL_PROCEDURE(glObjectPtrLabel);
    LOAD_OPENGL_PROCEDURE(glGetObjectPtrLabel);
    LOAD_OPENGL_PROCEDURE(glGetPointerv);
    LOAD_OPENGL_PROCEDURE(glEnablei);
    LOAD_OPENGL_PROCEDURE(glDisablei);
    LOAD_OPENGL_PROCEDURE(glBlendEquationi);
    LOAD_OPENGL_PROCEDURE(glBlendEquationSeparatei);
    LOAD_OPENGL_PROCEDURE(glBlendFunci);
    LOAD_OPENGL_PROCEDURE(glBlendFuncSeparatei);
    LOAD_OPENGL_PROCEDURE(glColorMaski);
    LOAD_OPENGL_PROCEDURE(glIsEnabledi);
    LOAD_OPENGL_PROCEDURE(glDrawElementsBaseVertex);
    LOAD_OPENGL_PROCEDURE(glDrawRangeElementsBaseVertex);
    LOAD_OPENGL_PROCEDURE(glDrawElementsInstancedBaseVertex);
    LOAD_OPENGL_PROCEDURE(glFramebufferTexture);
    LOAD_OPENGL_PROCEDURE(glPrimitiveBoundingBox);
    LOAD_OPENGL_PROCEDURE(glGetGraphicsResetStatus);
    LOAD_OPENGL_PROCEDURE(glReadnPixels);
    LOAD_OPENGL_PROCEDURE(glGetnUniformfv);
    LOAD_OPENGL_PROCEDURE(glGetnUniformiv);
    LOAD_OPENGL_PROCEDURE(glGetnUniformuiv);
    LOAD_OPENGL_PROCEDURE(glMinSampleShading);
    LOAD_OPENGL_PROCEDURE(glPatchParameteri);
    LOAD_OPENGL_PROCEDURE(glTexParameterIiv);
    LOAD_OPENGL_PROCEDURE(glTexParameterIuiv);
    LOAD_OPENGL_PROCEDURE(glGetTexParameterIiv);
    LOAD_OPENGL_PROCEDURE(glGetTexParameterIuiv);
    LOAD_OPENGL_PROCEDURE(glSamplerParameterIiv);
    LOAD_OPENGL_PROCEDURE(glSamplerParameterIuiv);
    LOAD_OPENGL_PROCEDURE(glGetSamplerParameterIiv);
    LOAD_OPENGL_PROCEDURE(glGetSamplerParameterIuiv);
    LOAD_OPENGL_PROCEDURE(glTexBuffer);
    LOAD_OPENGL_PROCEDURE(glTexBufferRange);
    LOAD_OPENGL_PROCEDURE(glTexStorage3DMultisample);
    #undef LOAD_OPENGL_PROCEDURE
    return 1;
}

#endif//GL_ES_VERSION_3_2
// ---------------------------------------------------------------------------------------------- //