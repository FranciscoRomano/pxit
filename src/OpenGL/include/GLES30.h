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
#ifndef __GLES30_h__
#define __GLES30_h__
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus
// ---------------------------------------------------------------------------------------------- //
#include "GLES20.h"
#include <GLES3/gl30.h>
#if GL_ES_VERSION_3_0

extern PFN_glReadBuffer                     glReadBuffer;
extern PFN_glDrawRangeElements              glDrawRangeElements;
extern PFN_glTexImage3D                     glTexImage3D;
extern PFN_glTexSubImage3D                  glTexSubImage3D;
extern PFN_glCopyTexSubImage3D              glCopyTexSubImage3D;
extern PFN_glCompressedTexImage3D           glCompressedTexImage3D;
extern PFN_glCompressedTexSubImage3D        glCompressedTexSubImage3D;
extern PFN_glGenQueries                     glGenQueries;
extern PFN_glDeleteQueries                  glDeleteQueries;
extern PFN_glIsQuery                        glIsQuery;
extern PFN_glBeginQuery                     glBeginQuery;
extern PFN_glEndQuery                       glEndQuery;
extern PFN_glGetQueryiv                     glGetQueryiv;
extern PFN_glGetQueryObjectuiv              glGetQueryObjectuiv;
extern PFN_glUnmapBuffer                    glUnmapBuffer;
extern PFN_glGetBufferPointerv              glGetBufferPointerv;
extern PFN_glDrawBuffers                    glDrawBuffers;
extern PFN_glUniformMatrix2x3fv             glUniformMatrix2x3fv;
extern PFN_glUniformMatrix3x2fv             glUniformMatrix3x2fv;
extern PFN_glUniformMatrix2x4fv             glUniformMatrix2x4fv;
extern PFN_glUniformMatrix4x2fv             glUniformMatrix4x2fv;
extern PFN_glUniformMatrix3x4fv             glUniformMatrix3x4fv;
extern PFN_glUniformMatrix4x3fv             glUniformMatrix4x3fv;
extern PFN_glBlitFramebuffer                glBlitFramebuffer;
extern PFN_glRenderbufferStorageMultisample glRenderbufferStorageMultisample;
extern PFN_glFramebufferTextureLayer        glFramebufferTextureLayer;
extern PFN_glMapBufferRange                 glMapBufferRange;
extern PFN_glFlushMappedBufferRange         glFlushMappedBufferRange;
extern PFN_glBindVertexArray                glBindVertexArray;
extern PFN_glDeleteVertexArrays             glDeleteVertexArrays;
extern PFN_glGenVertexArrays                glGenVertexArrays;
extern PFN_glIsVertexArray                  glIsVertexArray;
extern PFN_glGetIntegeri_v                  glGetIntegeri_v;
extern PFN_glBeginTransformFeedback         glBeginTransformFeedback;
extern PFN_glEndTransformFeedback           glEndTransformFeedback;
extern PFN_glBindBufferRange                glBindBufferRange;
extern PFN_glBindBufferBase                 glBindBufferBase;
extern PFN_glTransformFeedbackVaryings      glTransformFeedbackVaryings;
extern PFN_glGetTransformFeedbackVarying    glGetTransformFeedbackVarying;
extern PFN_glVertexAttribIPointer           glVertexAttribIPointer;
extern PFN_glGetVertexAttribIiv             glGetVertexAttribIiv;
extern PFN_glGetVertexAttribIuiv            glGetVertexAttribIuiv;
extern PFN_glVertexAttribI4i                glVertexAttribI4i;
extern PFN_glVertexAttribI4ui               glVertexAttribI4ui;
extern PFN_glVertexAttribI4iv               glVertexAttribI4iv;
extern PFN_glVertexAttribI4uiv              glVertexAttribI4uiv;
extern PFN_glGetUniformuiv                  glGetUniformuiv;
extern PFN_glGetFragDataLocation            glGetFragDataLocation;
extern PFN_glUniform1ui                     glUniform1ui;
extern PFN_glUniform2ui                     glUniform2ui;
extern PFN_glUniform3ui                     glUniform3ui;
extern PFN_glUniform4ui                     glUniform4ui;
extern PFN_glUniform1uiv                    glUniform1uiv;
extern PFN_glUniform2uiv                    glUniform2uiv;
extern PFN_glUniform3uiv                    glUniform3uiv;
extern PFN_glUniform4uiv                    glUniform4uiv;
extern PFN_glClearBufferiv                  glClearBufferiv;
extern PFN_glClearBufferuiv                 glClearBufferuiv;
extern PFN_glClearBufferfv                  glClearBufferfv;
extern PFN_glClearBufferfi                  glClearBufferfi;
extern PFN_glGetStringi                     glGetStringi;
extern PFN_glCopyBufferSubData              glCopyBufferSubData;
extern PFN_glGetUniformIndices              glGetUniformIndices;
extern PFN_glGetActiveUniformsiv            glGetActiveUniformsiv;
extern PFN_glGetUniformBlockIndex           glGetUniformBlockIndex;
extern PFN_glGetActiveUniformBlockiv        glGetActiveUniformBlockiv;
extern PFN_glGetActiveUniformBlockName      glGetActiveUniformBlockName;
extern PFN_glUniformBlockBinding            glUniformBlockBinding;
extern PFN_glDrawArraysInstanced            glDrawArraysInstanced;
extern PFN_glDrawElementsInstanced          glDrawElementsInstanced;
extern PFN_glFenceSync                      glFenceSync;
extern PFN_glIsSync                         glIsSync;
extern PFN_glDeleteSync                     glDeleteSync;
extern PFN_glClientWaitSync                 glClientWaitSync;
extern PFN_glWaitSync                       glWaitSync;
extern PFN_glGetInteger64v                  glGetInteger64v;
extern PFN_glGetSynciv                      glGetSynciv;
extern PFN_glGetInteger64i_v                glGetInteger64i_v;
extern PFN_glGetBufferParameteri64v         glGetBufferParameteri64v;
extern PFN_glGenSamplers                    glGenSamplers;
extern PFN_glDeleteSamplers                 glDeleteSamplers;
extern PFN_glIsSampler                      glIsSampler;
extern PFN_glBindSampler                    glBindSampler;
extern PFN_glSamplerParameteri              glSamplerParameteri;
extern PFN_glSamplerParameteriv             glSamplerParameteriv;
extern PFN_glSamplerParameterf              glSamplerParameterf;
extern PFN_glSamplerParameterfv             glSamplerParameterfv;
extern PFN_glGetSamplerParameteriv          glGetSamplerParameteriv;
extern PFN_glGetSamplerParameterfv          glGetSamplerParameterfv;
extern PFN_glVertexAttribDivisor            glVertexAttribDivisor;
extern PFN_glBindTransformFeedback          glBindTransformFeedback;
extern PFN_glDeleteTransformFeedbacks       glDeleteTransformFeedbacks;
extern PFN_glGenTransformFeedbacks          glGenTransformFeedbacks;
extern PFN_glIsTransformFeedback            glIsTransformFeedback;
extern PFN_glPauseTransformFeedback         glPauseTransformFeedback;
extern PFN_glResumeTransformFeedback        glResumeTransformFeedback;
extern PFN_glGetProgramBinary               glGetProgramBinary;
extern PFN_glProgramBinary                  glProgramBinary;
extern PFN_glProgramParameteri              glProgramParameteri;
extern PFN_glInvalidateFramebuffer          glInvalidateFramebuffer;
extern PFN_glInvalidateSubFramebuffer       glInvalidateSubFramebuffer;
extern PFN_glTexStorage2D                   glTexStorage2D;
extern PFN_glTexStorage3D                   glTexStorage3D;
extern PFN_glGetInternalformativ            glGetInternalformativ;

/// @brief Returns "1" if all OpenGL ES 3.0 procedures were loaded successfully.
/// @param pfnGetProc A function pointer to a OpenGL procedure loader.
int LoadOpenGLES30(void* (*pfnLoadProc)(const char* name));

#endif//GL_ES_VERSION_3_0
// ---------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif//__cplusplus
#endif//__GLES30_h__
// ---------------------------------------------------------------------------------------------- //