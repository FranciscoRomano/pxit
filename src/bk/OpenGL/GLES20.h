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
#ifndef __GLES20_h__
#define __GLES20_h__
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus
// ---------------------------------------------------------------------------------------------- //
#include <GLES2/gl20.h>
#if GL_ES_VERSION_2_0

extern PFN_glActiveTexture                       glActiveTexture;
extern PFN_glAttachShader                        glAttachShader;
extern PFN_glBindAttribLocation                  glBindAttribLocation;
extern PFN_glBindBuffer                          glBindBuffer;
extern PFN_glBindFramebuffer                     glBindFramebuffer;
extern PFN_glBindRenderbuffer                    glBindRenderbuffer;
extern PFN_glBindTexture                         glBindTexture;
extern PFN_glBlendColor                          glBlendColor;
extern PFN_glBlendEquation                       glBlendEquation;
extern PFN_glBlendEquationSeparate               glBlendEquationSeparate;
extern PFN_glBlendFunc                           glBlendFunc;
extern PFN_glBlendFuncSeparate                   glBlendFuncSeparate;
extern PFN_glBufferData                          glBufferData;
extern PFN_glBufferSubData                       glBufferSubData;
extern PFN_glCheckFramebufferStatus              glCheckFramebufferStatus;
extern PFN_glClear                               glClear;
extern PFN_glClearColor                          glClearColor;
extern PFN_glClearDepthf                         glClearDepthf;
extern PFN_glClearStencil                        glClearStencil;
extern PFN_glColorMask                           glColorMask;
extern PFN_glCompileShader                       glCompileShader;
extern PFN_glCompressedTexImage2D                glCompressedTexImage2D;
extern PFN_glCompressedTexSubImage2D             glCompressedTexSubImage2D;
extern PFN_glCopyTexImage2D                      glCopyTexImage2D;
extern PFN_glCopyTexSubImage2D                   glCopyTexSubImage2D;
extern PFN_glCreateProgram                       glCreateProgram;
extern PFN_glCreateShader                        glCreateShader;
extern PFN_glCullFace                            glCullFace;
extern PFN_glDeleteBuffers                       glDeleteBuffers;
extern PFN_glDeleteFramebuffers                  glDeleteFramebuffers;
extern PFN_glDeleteProgram                       glDeleteProgram;
extern PFN_glDeleteRenderbuffers                 glDeleteRenderbuffers;
extern PFN_glDeleteShader                        glDeleteShader;
extern PFN_glDeleteTextures                      glDeleteTextures;
extern PFN_glDepthFunc                           glDepthFunc;
extern PFN_glDepthMask                           glDepthMask;
extern PFN_glDepthRangef                         glDepthRangef;
extern PFN_glDetachShader                        glDetachShader;
extern PFN_glDisable                             glDisable;
extern PFN_glDisableVertexAttribArray            glDisableVertexAttribArray;
extern PFN_glDrawArrays                          glDrawArrays;
extern PFN_glDrawElements                        glDrawElements;
extern PFN_glEnable                              glEnable;
extern PFN_glEnableVertexAttribArray             glEnableVertexAttribArray;
extern PFN_glFinish                              glFinish;
extern PFN_glFlush                               glFlush;
extern PFN_glFramebufferRenderbuffer             glFramebufferRenderbuffer;
extern PFN_glFramebufferTexture2D                glFramebufferTexture2D;
extern PFN_glFrontFace                           glFrontFace;
extern PFN_glGenBuffers                          glGenBuffers;
extern PFN_glGenerateMipmap                      glGenerateMipmap;
extern PFN_glGenFramebuffers                     glGenFramebuffers;
extern PFN_glGenRenderbuffers                    glGenRenderbuffers;
extern PFN_glGenTextures                         glGenTextures;
extern PFN_glGetActiveAttrib                     glGetActiveAttrib;
extern PFN_glGetActiveUniform                    glGetActiveUniform;
extern PFN_glGetAttachedShaders                  glGetAttachedShaders;
extern PFN_glGetAttribLocation                   glGetAttribLocation;
extern PFN_glGetBooleanv                         glGetBooleanv;
extern PFN_glGetBufferParameteriv                glGetBufferParameteriv;
extern PFN_glGetError                            glGetError;
extern PFN_glGetFloatv                           glGetFloatv;
extern PFN_glGetFramebufferAttachmentParameteriv glGetFramebufferAttachmentParameteriv;
extern PFN_glGetIntegerv                         glGetIntegerv;
extern PFN_glGetProgramiv                        glGetProgramiv;
extern PFN_glGetProgramInfoLog                   glGetProgramInfoLog;
extern PFN_glGetRenderbufferParameteriv          glGetRenderbufferParameteriv;
extern PFN_glGetShaderiv                         glGetShaderiv;
extern PFN_glGetShaderInfoLog                    glGetShaderInfoLog;
extern PFN_glGetShaderPrecisionFormat            glGetShaderPrecisionFormat;
extern PFN_glGetShaderSource                     glGetShaderSource;
extern PFN_glGetString                           glGetString;
extern PFN_glGetTexParameterfv                   glGetTexParameterfv;
extern PFN_glGetTexParameteriv                   glGetTexParameteriv;
extern PFN_glGetUniformfv                        glGetUniformfv;
extern PFN_glGetUniformiv                        glGetUniformiv;
extern PFN_glGetUniformLocation                  glGetUniformLocation;
extern PFN_glGetVertexAttribfv                   glGetVertexAttribfv;
extern PFN_glGetVertexAttribiv                   glGetVertexAttribiv;
extern PFN_glGetVertexAttribPointerv             glGetVertexAttribPointerv;
extern PFN_glHint                                glHint;
extern PFN_glIsBuffer                            glIsBuffer;
extern PFN_glIsEnabled                           glIsEnabled;
extern PFN_glIsFramebuffer                       glIsFramebuffer;
extern PFN_glIsProgram                           glIsProgram;
extern PFN_glIsRenderbuffer                      glIsRenderbuffer;
extern PFN_glIsShader                            glIsShader;
extern PFN_glIsTexture                           glIsTexture;
extern PFN_glLineWidth                           glLineWidth;
extern PFN_glLinkProgram                         glLinkProgram;
extern PFN_glPixelStorei                         glPixelStorei;
extern PFN_glPolygonOffset                       glPolygonOffset;
extern PFN_glReadPixels                          glReadPixels;
extern PFN_glReleaseShaderCompiler               glReleaseShaderCompiler;
extern PFN_glRenderbufferStorage                 glRenderbufferStorage;
extern PFN_glSampleCoverage                      glSampleCoverage;
extern PFN_glScissor                             glScissor;
extern PFN_glShaderBinary                        glShaderBinary;
extern PFN_glShaderSource                        glShaderSource;
extern PFN_glStencilFunc                         glStencilFunc;
extern PFN_glStencilFuncSeparate                 glStencilFuncSeparate;
extern PFN_glStencilMask                         glStencilMask;
extern PFN_glStencilMaskSeparate                 glStencilMaskSeparate;
extern PFN_glStencilOp                           glStencilOp;
extern PFN_glStencilOpSeparate                   glStencilOpSeparate;
extern PFN_glTexImage2D                          glTexImage2D;
extern PFN_glTexParameterf                       glTexParameterf;
extern PFN_glTexParameterfv                      glTexParameterfv;
extern PFN_glTexParameteri                       glTexParameteri;
extern PFN_glTexParameteriv                      glTexParameteriv;
extern PFN_glTexSubImage2D                       glTexSubImage2D;
extern PFN_glUniform1f                           glUniform1f;
extern PFN_glUniform1fv                          glUniform1fv;
extern PFN_glUniform1i                           glUniform1i;
extern PFN_glUniform1iv                          glUniform1iv;
extern PFN_glUniform2f                           glUniform2f;
extern PFN_glUniform2fv                          glUniform2fv;
extern PFN_glUniform2i                           glUniform2i;
extern PFN_glUniform2iv                          glUniform2iv;
extern PFN_glUniform3f                           glUniform3f;
extern PFN_glUniform3fv                          glUniform3fv;
extern PFN_glUniform3i                           glUniform3i;
extern PFN_glUniform3iv                          glUniform3iv;
extern PFN_glUniform4f                           glUniform4f;
extern PFN_glUniform4fv                          glUniform4fv;
extern PFN_glUniform4i                           glUniform4i;
extern PFN_glUniform4iv                          glUniform4iv;
extern PFN_glUniformMatrix2fv                    glUniformMatrix2fv;
extern PFN_glUniformMatrix3fv                    glUniformMatrix3fv;
extern PFN_glUniformMatrix4fv                    glUniformMatrix4fv;
extern PFN_glUseProgram                          glUseProgram;
extern PFN_glValidateProgram                     glValidateProgram;
extern PFN_glVertexAttrib1f                      glVertexAttrib1f;
extern PFN_glVertexAttrib1fv                     glVertexAttrib1fv;
extern PFN_glVertexAttrib2f                      glVertexAttrib2f;
extern PFN_glVertexAttrib2fv                     glVertexAttrib2fv;
extern PFN_glVertexAttrib3f                      glVertexAttrib3f;
extern PFN_glVertexAttrib3fv                     glVertexAttrib3fv;
extern PFN_glVertexAttrib4f                      glVertexAttrib4f;
extern PFN_glVertexAttrib4fv                     glVertexAttrib4fv;
extern PFN_glVertexAttribPointer                 glVertexAttribPointer;
extern PFN_glViewport                            glViewport;

/// @brief Returns "1" if all OpenGL ES 2.0 procedures were loaded successfully.
/// @param pfnGetProc A function pointer to a OpenGL procedure loader.
int LoadOpenGLES20(void* (*pfnLoadProc)(const char* name));

#endif//GL_ES_VERSION_2_0
// ---------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif//__cplusplus
#endif//__GLES20_h__
// ---------------------------------------------------------------------------------------------- //