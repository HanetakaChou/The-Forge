/*
 * Copyright (c) 2018-2021 The Forge Interactive Inc.
 *
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

/* Write your header comments here */
#version 450 core


layout(location = 0) in vec2 fragInput_TEXCOORD0;
layout(location = 1) in vec4 fragInput_TEXCOORD1;
layout(location = 0) out float rast_FragData0; 

struct VSOutput
{
    vec4 Position;
    vec2 UV;
    vec4 MiscData;
};
layout(UPDATE_FREQ_NONE, binding = 1) uniform sampler clampToEdgeNearSampler;
layout(UPDATE_FREQ_NONE, binding = 0) uniform texture2D DepthPassTexture;
float HLSLmain(VSOutput input1)
{
    float tileDepth = float (textureLod(sampler2D( DepthPassTexture, clampToEdgeNearSampler), vec2((input1).UV), float (0.0)));
    return tileDepth;
}
void main()
{
    VSOutput input1;
    input1.Position = vec4(gl_FragCoord.xyz, 1.0 / gl_FragCoord.w);
    input1.UV = fragInput_TEXCOORD0;
    input1.MiscData = fragInput_TEXCOORD1;
    float result = HLSLmain(input1);
    rast_FragData0 = result;
}
