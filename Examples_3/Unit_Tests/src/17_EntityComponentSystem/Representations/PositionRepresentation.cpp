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

#include "PositionRepresentation.h"

#include "../../../../../Common_3/OS/Interfaces/IMemory.h"
using namespace FCR;

FORGE_DEFINE_COMPONENT_ID(PositionComponent)

FORGE_ASSIGN_UNIQUE_ID_TO_REGISTERED_COMPONENT(PositionComponent, x, 0)
FORGE_ASSIGN_UNIQUE_ID_TO_REGISTERED_COMPONENT(PositionComponent, y, 1)

FORGE_START_VAR_REPRESENTATIONS_BUILD(PositionComponent)
FORGE_INIT_COMPONENT_ID(PositionComponent)
FORGE_CREATE_VAR_REPRESENTATION(PositionComponent, x)
FORGE_FINALIZE_VAR_REPRESENTATION(x, "x", ComponentVarType::FLOAT, ComponentVarAccess::READ_WRITE)

FORGE_CREATE_VAR_REPRESENTATION(PositionComponent, y)
FORGE_FINALIZE_VAR_REPRESENTATION(y, "y", ComponentVarType::FLOAT, ComponentVarAccess::READ_WRITE)

FORGE_END_VAR_REPRESENTATIONS_BUILD(PositionComponent)



FORGE_START_VAR_REFERENCES(PositionComponent)

FORGE_ADD_VAR_REF(PositionComponent, x, x)
FORGE_ADD_VAR_REF(PositionComponent, y, y)

FORGE_END_VAR_REFERENCES
