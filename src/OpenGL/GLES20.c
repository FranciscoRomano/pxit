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
#include <GLES20.h>
#if GL_ES_VERSION_2_0

PFN_glActiveTexture                       glActiveTexture;
PFN_glAttachShader                        glAttachShader;
PFN_glBindAttribLocation                  glBindAttribLocation;
PFN_glBindBuffer                          glBindBuffer;
PFN_glBindFramebuffer                     glBindFramebuffer;
PFN_glBindRenderbuffer                    glBindRenderbuffer;
PFN_glBindTexture                         glBindTexture;
PFN_glBlendColor                          glBlendColor;
PFN_glBlendEquation                       glBlendEquation;
PFN_glBlendEquationSeparate               glBlendEquationSeparate;
PFN_glBlendFunc                           glBlendFunc;
PFN_glBlendFuncSeparate                   glBlendFuncSeparate;
PFN_glBufferData                          glBufferData;
PFN_glBufferSubData                       glBufferSubData;
PFN_glCheckFramebufferStatus              glCheckFramebufferStatus;
PFN_glClear                               glClear;
PFN_glClearColor                          glClearColor;
PFN_glClearDepthf                         glClearDepthf;
PFN_glClearStencil                        glClearStencil;
PFN_glColorMask                           glColorMask;
PFN_glCompileShader                       glCompileShader;
PFN_glCompressedTexImage2D                glCompressedTexImage2D;
PFN_glCompressedTexSubImage2D             glCompressedTexSubImage2D;
PFN_glCopyTexImage2D                      glCopyTexImage2D;
PFN_glCopyTexSubImage2D                   glCopyTexSubImage2D;
PFN_glCreateProgram                       glCreateProgram;
PFN_glCreateShader                        glCreateShader;
PFN_glCullFace                            glCullFace;
PFN_glDeleteBuffers                       glDeleteBuffers;
PFN_glDeleteFramebuffers                  glDeleteFramebuffers;
PFN_glDeleteProgram                       glDeleteProgram;
PFN_glDeleteRenderbuffers                 glDeleteRenderbuffers;
PFN_glDeleteShader                        glDeleteShader;
PFN_glDeleteTextures                      glDeleteTextures;
PFN_glDepthFunc                           glDepthFunc;
PFN_glDepthMask                           glDepthMask;
PFN_glDepthRangef                         glDepthRangef;
PFN_glDetachShader                        glDetachShader;
PFN_glDisable                             glDisable;
PFN_glDisableVertexAttribArray            glDisableVertexAttribArray;
PFN_glDrawArrays                          glDrawArrays;
PFN_glDrawElements                        glDrawElements;
PFN_glEnable                              glEnable;
PFN_glEnableVertexAttribArray             glEnableVertexAttribArray;
PFN_glFinish                              glFinish;
PFN_glFlush                               glFlush;
PFN_glFramebufferRenderbuffer             glFramebufferRenderbuffer;
PFN_glFramebufferTexture2D                glFramebufferTexture2D;
PFN_glFrontFace                           glFrontFace;
PFN_glGenBuffers                          glGenBuffers;
PFN_glGenerateMipmap                      glGenerateMipmap;
PFN_glGenFramebuffers                     glGenFramebuffers;
PFN_glGenRenderbuffers                    glGenRenderbuffers;
PFN_glGenTextures                         glGenTextures;
PFN_glGetActiveAttrib                     glGetActiveAttrib;
PFN_glGetActiveUniform                    glGetActiveUniform;
PFN_glGetAttachedShaders                  glGetAttachedShaders;
PFN_glGetAttribLocation                   glGetAttribLocation;
PFN_glGetBooleanv                         glGetBooleanv;
PFN_glGetBufferParameteriv                glGetBufferParameteriv;
PFN_glGetError                            glGetError;
PFN_glGetFloatv                           glGetFloatv;
PFN_glGetFramebufferAttachmentParameteriv glGetFramebufferAttachmentParameteriv;
PFN_glGetIntegerv                         glGetIntegerv;
PFN_glGetProgramiv                        glGetProgramiv;
PFN_glGetProgramInfoLog                   glGetProgramInfoLog;
PFN_glGetRenderbufferParameteriv          glGetRenderbufferParameteriv;
PFN_glGetShaderiv                         glGetShaderiv;
PFN_glGetShaderInfoLog                    glGetShaderInfoLog;
PFN_glGetShaderPrecisionFormat            glGetShaderPrecisionFormat;
PFN_glGetShaderSource                     glGetShaderSource;
PFN_glGetString                           glGetString;
PFN_glGetTexParameterfv                   glGetTexParameterfv;
PFN_glGetTexParameteriv                   glGetTexParameteriv;
PFN_glGetUniformfv                        glGetUniformfv;
PFN_glGetUniformiv                        glGetUniformiv;
PFN_glGetUniformLocation                  glGetUniformLocation;
PFN_glGetVertexAttribfv                   glGetVertexAttribfv;
PFN_glGetVertexAttribiv                   glGetVertexAttribiv;
PFN_glGetVertexAttribPointerv             glGetVertexAttribPointerv;
PFN_glHint                                glHint;
PFN_glIsBuffer                            glIsBuffer;
PFN_glIsEnabled                           glIsEnabled;
PFN_glIsFramebuffer                       glIsFramebuffer;
PFN_glIsProgram                           glIsProgram;
PFN_glIsRenderbuffer                      glIsRenderbuffer;
PFN_glIsShader                            glIsShader;
PFN_glIsTexture                           glIsTexture;
PFN_glLineWidth                           glLineWidth;
PFN_glLinkProgram                         glLinkProgram;
PFN_glPixelStorei                         glPixelStorei;
PFN_glPolygonOffset                       glPolygonOffset;
PFN_glReadPixels                          glReadPixels;
PFN_glReleaseShaderCompiler               glReleaseShaderCompiler;
PFN_glRenderbufferStorage                 glRenderbufferStorage;
PFN_glSampleCoverage                      glSampleCoverage;
PFN_glScissor                             glScissor;
PFN_glShaderBinary                        glShaderBinary;
PFN_glShaderSource                        glShaderSource;
PFN_glStencilFunc                         glStencilFunc;
PFN_glStencilFuncSeparate                 glStencilFuncSeparate;
PFN_glStencilMask                         glStencilMask;
PFN_glStencilMaskSeparate                 glStencilMaskSeparate;
PFN_glStencilOp                           glStencilOp;
PFN_glStencilOpSeparate                   glStencilOpSeparate;
PFN_glTexImage2D                          glTexImage2D;
PFN_glTexParameterf                       glTexParameterf;
PFN_glTexParameterfv                      glTexParameterfv;
PFN_glTexParameteri                       glTexParameteri;
PFN_glTexParameteriv                      glTexParameteriv;
PFN_glTexSubImage2D                       glTexSubImage2D;
PFN_glUniform1f                           glUniform1f;
PFN_glUniform1fv                          glUniform1fv;
PFN_glUniform1i                           glUniform1i;
PFN_glUniform1iv                          glUniform1iv;
PFN_glUniform2f                           glUniform2f;
PFN_glUniform2fv                          glUniform2fv;
PFN_glUniform2i                           glUniform2i;
PFN_glUniform2iv                          glUniform2iv;
PFN_glUniform3f                           glUniform3f;
PFN_glUniform3fv                          glUniform3fv;
PFN_glUniform3i                           glUniform3i;
PFN_glUniform3iv                          glUniform3iv;
PFN_glUniform4f                           glUniform4f;
PFN_glUniform4fv                          glUniform4fv;
PFN_glUniform4i                           glUniform4i;
PFN_glUniform4iv                          glUniform4iv;
PFN_glUniformMatrix2fv                    glUniformMatrix2fv;
PFN_glUniformMatrix3fv                    glUniformMatrix3fv;
PFN_glUniformMatrix4fv                    glUniformMatrix4fv;
PFN_glUseProgram                          glUseProgram;
PFN_glValidateProgram                     glValidateProgram;
PFN_glVertexAttrib1f                      glVertexAttrib1f;
PFN_glVertexAttrib1fv                     glVertexAttrib1fv;
PFN_glVertexAttrib2f                      glVertexAttrib2f;
PFN_glVertexAttrib2fv                     glVertexAttrib2fv;
PFN_glVertexAttrib3f                      glVertexAttrib3f;
PFN_glVertexAttrib3fv                     glVertexAttrib3fv;
PFN_glVertexAttrib4f                      glVertexAttrib4f;
PFN_glVertexAttrib4fv                     glVertexAttrib4fv;
PFN_glVertexAttribPointer                 glVertexAttribPointer;
PFN_glViewport                            glViewport;

int LoadOpenGLES20(void* (*pfnLoadProc)(const char* name))
{
    #define LOAD_OPENGL_PROCEDURE(name)\
    name = (PFN_##name)pfnLoadProc(#name); if (!name) return 0;
    LOAD_OPENGL_PROCEDURE(glActiveTexture);
    LOAD_OPENGL_PROCEDURE(glAttachShader);
    LOAD_OPENGL_PROCEDURE(glBindAttribLocation);
    LOAD_OPENGL_PROCEDURE(glBindBuffer);
    LOAD_OPENGL_PROCEDURE(glBindFramebuffer);
    LOAD_OPENGL_PROCEDURE(glBindRenderbuffer);
    LOAD_OPENGL_PROCEDURE(glBindTexture);
    LOAD_OPENGL_PROCEDURE(glBlendColor);
    LOAD_OPENGL_PROCEDURE(glBlendEquation);
    LOAD_OPENGL_PROCEDURE(glBlendEquationSeparate);
    LOAD_OPENGL_PROCEDURE(glBlendFunc);
    LOAD_OPENGL_PROCEDURE(glBlendFuncSeparate);
    LOAD_OPENGL_PROCEDURE(glBufferData);
    LOAD_OPENGL_PROCEDURE(glBufferSubData);
    LOAD_OPENGL_PROCEDURE(glCheckFramebufferStatus);
    LOAD_OPENGL_PROCEDURE(glClear);
    LOAD_OPENGL_PROCEDURE(glClearColor);
    LOAD_OPENGL_PROCEDURE(glClearDepthf);
    LOAD_OPENGL_PROCEDURE(glClearStencil);
    LOAD_OPENGL_PROCEDURE(glColorMask);
    LOAD_OPENGL_PROCEDURE(glCompileShader);
    LOAD_OPENGL_PROCEDURE(glCompressedTexImage2D);
    LOAD_OPENGL_PROCEDURE(glCompressedTexSubImage2D);
    LOAD_OPENGL_PROCEDURE(glCopyTexImage2D);
    LOAD_OPENGL_PROCEDURE(glCopyTexSubImage2D);
    LOAD_OPENGL_PROCEDURE(glCreateProgram);
    LOAD_OPENGL_PROCEDURE(glCreateShader);
    LOAD_OPENGL_PROCEDURE(glCullFace);
    LOAD_OPENGL_PROCEDURE(glDeleteBuffers);
    LOAD_OPENGL_PROCEDURE(glDeleteFramebuffers);
    LOAD_OPENGL_PROCEDURE(glDeleteProgram);
    LOAD_OPENGL_PROCEDURE(glDeleteRenderbuffers);
    LOAD_OPENGL_PROCEDURE(glDeleteShader);
    LOAD_OPENGL_PROCEDURE(glDeleteTextures);
    LOAD_OPENGL_PROCEDURE(glDepthFunc);
    LOAD_OPENGL_PROCEDURE(glDepthMask);
    LOAD_OPENGL_PROCEDURE(glDepthRangef);
    LOAD_OPENGL_PROCEDURE(glDetachShader);
    LOAD_OPENGL_PROCEDURE(glDisable);
    LOAD_OPENGL_PROCEDURE(glDisableVertexAttribArray);
    LOAD_OPENGL_PROCEDURE(glDrawArrays);
    LOAD_OPENGL_PROCEDURE(glDrawElements);
    LOAD_OPENGL_PROCEDURE(glEnable);
    LOAD_OPENGL_PROCEDURE(glEnableVertexAttribArray);
    LOAD_OPENGL_PROCEDURE(glFinish);
    LOAD_OPENGL_PROCEDURE(glFlush);
    LOAD_OPENGL_PROCEDURE(glFramebufferRenderbuffer);
    LOAD_OPENGL_PROCEDURE(glFramebufferTexture2D);
    LOAD_OPENGL_PROCEDURE(glFrontFace);
    LOAD_OPENGL_PROCEDURE(glGenBuffers);
    LOAD_OPENGL_PROCEDURE(glGenerateMipmap);
    LOAD_OPENGL_PROCEDURE(glGenFramebuffers);
    LOAD_OPENGL_PROCEDURE(glGenRenderbuffers);
    LOAD_OPENGL_PROCEDURE(glGenTextures);
    LOAD_OPENGL_PROCEDURE(glGetActiveAttrib);
    LOAD_OPENGL_PROCEDURE(glGetActiveUniform);
    LOAD_OPENGL_PROCEDURE(glGetAttachedShaders);
    LOAD_OPENGL_PROCEDURE(glGetAttribLocation);
    LOAD_OPENGL_PROCEDURE(glGetBooleanv);
    LOAD_OPENGL_PROCEDURE(glGetBufferParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetError);
    LOAD_OPENGL_PROCEDURE(glGetFloatv);
    LOAD_OPENGL_PROCEDURE(glGetFramebufferAttachmentParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetIntegerv);
    LOAD_OPENGL_PROCEDURE(glGetProgramiv);
    LOAD_OPENGL_PROCEDURE(glGetProgramInfoLog);
    LOAD_OPENGL_PROCEDURE(glGetRenderbufferParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetShaderiv);
    LOAD_OPENGL_PROCEDURE(glGetShaderInfoLog);
    LOAD_OPENGL_PROCEDURE(glGetShaderPrecisionFormat);
    LOAD_OPENGL_PROCEDURE(glGetShaderSource);
    LOAD_OPENGL_PROCEDURE(glGetString);
    LOAD_OPENGL_PROCEDURE(glGetTexParameterfv);
    LOAD_OPENGL_PROCEDURE(glGetTexParameteriv);
    LOAD_OPENGL_PROCEDURE(glGetUniformfv);
    LOAD_OPENGL_PROCEDURE(glGetUniformiv);
    LOAD_OPENGL_PROCEDURE(glGetUniformLocation);
    LOAD_OPENGL_PROCEDURE(glGetVertexAttribfv);
    LOAD_OPENGL_PROCEDURE(glGetVertexAttribiv);
    LOAD_OPENGL_PROCEDURE(glGetVertexAttribPointerv);
    LOAD_OPENGL_PROCEDURE(glHint);
    LOAD_OPENGL_PROCEDURE(glIsBuffer);
    LOAD_OPENGL_PROCEDURE(glIsEnabled);
    LOAD_OPENGL_PROCEDURE(glIsFramebuffer);
    LOAD_OPENGL_PROCEDURE(glIsProgram);
    LOAD_OPENGL_PROCEDURE(glIsRenderbuffer);
    LOAD_OPENGL_PROCEDURE(glIsShader);
    LOAD_OPENGL_PROCEDURE(glIsTexture);
    LOAD_OPENGL_PROCEDURE(glLineWidth);
    LOAD_OPENGL_PROCEDURE(glLinkProgram);
    LOAD_OPENGL_PROCEDURE(glPixelStorei);
    LOAD_OPENGL_PROCEDURE(glPolygonOffset);
    LOAD_OPENGL_PROCEDURE(glReadPixels);
    LOAD_OPENGL_PROCEDURE(glReleaseShaderCompiler);
    LOAD_OPENGL_PROCEDURE(glRenderbufferStorage);
    LOAD_OPENGL_PROCEDURE(glSampleCoverage);
    LOAD_OPENGL_PROCEDURE(glScissor);
    LOAD_OPENGL_PROCEDURE(glShaderBinary);
    LOAD_OPENGL_PROCEDURE(glShaderSource);
    LOAD_OPENGL_PROCEDURE(glStencilFunc);
    LOAD_OPENGL_PROCEDURE(glStencilFuncSeparate);
    LOAD_OPENGL_PROCEDURE(glStencilMask);
    LOAD_OPENGL_PROCEDURE(glStencilMaskSeparate);
    LOAD_OPENGL_PROCEDURE(glStencilOp);
    LOAD_OPENGL_PROCEDURE(glStencilOpSeparate);
    LOAD_OPENGL_PROCEDURE(glTexImage2D);
    LOAD_OPENGL_PROCEDURE(glTexParameterf);
    LOAD_OPENGL_PROCEDURE(glTexParameterfv);
    LOAD_OPENGL_PROCEDURE(glTexParameteri);
    LOAD_OPENGL_PROCEDURE(glTexParameteriv);
    LOAD_OPENGL_PROCEDURE(glTexSubImage2D);
    LOAD_OPENGL_PROCEDURE(glUniform1f);
    LOAD_OPENGL_PROCEDURE(glUniform1fv);
    LOAD_OPENGL_PROCEDURE(glUniform1i);
    LOAD_OPENGL_PROCEDURE(glUniform1iv);
    LOAD_OPENGL_PROCEDURE(glUniform2f);
    LOAD_OPENGL_PROCEDURE(glUniform2fv);
    LOAD_OPENGL_PROCEDURE(glUniform2i);
    LOAD_OPENGL_PROCEDURE(glUniform2iv);
    LOAD_OPENGL_PROCEDURE(glUniform3f);
    LOAD_OPENGL_PROCEDURE(glUniform3fv);
    LOAD_OPENGL_PROCEDURE(glUniform3i);
    LOAD_OPENGL_PROCEDURE(glUniform3iv);
    LOAD_OPENGL_PROCEDURE(glUniform4f);
    LOAD_OPENGL_PROCEDURE(glUniform4fv);
    LOAD_OPENGL_PROCEDURE(glUniform4i);
    LOAD_OPENGL_PROCEDURE(glUniform4iv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix2fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix3fv);
    LOAD_OPENGL_PROCEDURE(glUniformMatrix4fv);
    LOAD_OPENGL_PROCEDURE(glUseProgram);
    LOAD_OPENGL_PROCEDURE(glValidateProgram);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib1f);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib1fv);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib2f);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib2fv);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib3f);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib3fv);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib4f);
    LOAD_OPENGL_PROCEDURE(glVertexAttrib4fv);
    LOAD_OPENGL_PROCEDURE(glVertexAttribPointer);
    LOAD_OPENGL_PROCEDURE(glViewport);
    #undef LOAD_OPENGL_PROCEDURE
    return 1;
}

#endif//GL_ES_VERSION_2_0
// ---------------------------------------------------------------------------------------------- //