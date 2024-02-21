% This script configures the code generation options of the current
% Simulink schematic to default values.
% MATLAB version: 9.6.0.1214997 (R2019a) Update 6
%
% Copyright 2020 NXP
% NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
% accordance with the applicable license terms.  By expressly accepting such terms or by
% downloading, installing, activating and/or otherwise using the software, you are agreeing that
% you have read, and that you agree to comply with and are bound by, such license terms.  If you
% do not agree to be bound by the applicable license terms, then you may not retain, install,
% activate or otherwise use the software.

model = gcs;
cs = getActiveConfigSet(model);

% ---------------------------------------

% Original environment character encoding: windows-1252
if ~strcmpi(get_param(0, 'CharacterEncoding'), 'windows-1252')
    warning('Simulink:EncodingUnMatched', 'The target character encoding (%s) is different from the original (%s).',  get_param(0, 'CharacterEncoding'), 'windows-1252');
end

% Do not change the order of the following commands. There are dependencies between the parameters.
cs.set_param('Name', 'Configuration'); % Name
cs.set_param('Description', 'Default configuration'); % Description

% Original configuration set target is ert.tlc
cs.switchTarget('ert.tlc','');

% Solver
cs.set_param('Solver', 'FixedStepAuto');   % Solver

% Data Import/Export
cs.set_param('SaveFormat', 'Dataset');   % Format

% Diagnostics
cs.set_param('BusObjectLabelMismatch', 'error');   % Element name mismatch

% Hardware Implementation
cs.set_param('ProdHWDeviceType', 'ARM Compatible->ARM 8');   % Production device vendor and type
cs.set_param('ProdLongLongMode', 'on');   % Support long long
cs.set_param('ProdEndianess', 'LittleEndian');   % Byte ordering
cs.set_param('ProdIntDivRoundTo', 'Zero');   % Production hardware signed integer division rounds to
cs.set_param('ProdShiftRightIntArith', 'on');   % Shift right on a signed integer as arithmetic shift
cs.set_param('ProdEqTarget', 'on');   % Test hardware is the same as production hardware
cs.set_param('TargetPreprocMaxBitsSint', 32);   % Maximum bits for signed integer in C preprocessor
cs.set_param('TargetPreprocMaxBitsUint', 32);   % Maximum bits for unsigned integer in C preprocessor
cs.set_param('HardwareBoardFeatureSet', 'EmbeddedCoderHSP');   % Feature set for selected hardware board

% Simulation Target
cs.set_param('SimGenImportedTypeDefs', 'off');   % Generate typedefs for imported bus and enumeration types
cs.set_param('SimParseCustomCode', 'on');   % Import custom code
cs.set_param('SimUserIncludeDirs', 'C:\NXP\AMMCLIB\S32K3xx_AMMCLIB_v1.1.34\include');   % Include directories
cs.set_param('SimUserLibraries', 'C:\NXP\AMMCLIB\S32K3xx_AMMCLIB_v1.1.34\lib\mingw_x64\libS32K3xx_AMMCLIB.a');   % Libraries

% Code Generation
cs.set_param('TargetLang', 'C');   % Language
cs.set_param('Toolchain', 'MinGW64 | gmake (64-bit Windows)');   % Toolchain
cs.set_param('GenCodeOnly', 'on');   % Generate code only
cs.set_param('RTWUseSimCustomCode', 'off');   % Use the same custom code settings as Simulation Target
cs.set_param('CodeInterfacePackaging', 'Nonreusable function');   % Code interface packaging
cs.set_param('CombineOutputUpdateFcns', 'on');   % Single output/update function
cs.set_param('CombineSignalStateStructs', 'on');   % Combine signal/state structures
cs.set_param('ArrayLayout', 'Column-major');   % Array layout
cs.set_param('GenerateSampleERTMain', 'off');   % Generate an example main program
cs.set_param('ERTFilePackagingFormat', 'Compact');   % File packaging format
cs.set_param('EnableUserReplacementTypes', 'on');   % Replace data type names in the generated code
cs.set_param('ReplacementTypes', struct('double','tDouble','single','tFloat','int32','tS32','int16','tS16','int8','tS8','uint32','tU32','uint16','tU16','uint8','tU8','boolean','','int','','uint','','char','','uint64','tU64','int64','tS64'));   % Data type names
