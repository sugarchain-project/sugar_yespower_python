/*-
 * Copyright 2018 Cryply team
 * Copyright 2018 bitzenyPlus Developers
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file was originally written by Cryply team as part of the Cryply
 * coin.
 */

#include <Python.h>
#include "yespower.h"
#include "sysendian.h"
#include "sha256.h"

#include <stdlib.h>

static const yespower_params_t yespower_0_5_sugar = {YESPOWER_0_5, 2048, 8, "Client Key", 10};
static const yespower_params_t yespower_1_0_sugar = {YESPOWER_1_0, 2048, 32, NULL, 0};

int yespower_hash(const uint8_t *input, char *output)
{
    if (yespower_tls(input, 80, &yespower_1_0_sugar, (yespower_binary_t *) output))
      abort();
}

static PyObject *yespower_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
    PyStringObject *input;
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

    yespower_hash((uint8_t *)PyString_AsString((PyObject*) input), output);
    Py_DECREF(input);
    value = Py_BuildValue("s#", output, 32);
    PyMem_Free(output);
    return value;
}

static PyMethodDef YespowerMethods[] = {
    { "getPoWHash", yespower_getpowhash, METH_VARARGS, "Returns the proof of work hash using yespower-1.0.0" },
    { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initsugar_yespower(void) {
    (void) Py_InitModule("sugar_yespower", YespowerMethods);
}
