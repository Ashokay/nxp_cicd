% SLBLOCKS Defines the block library for a specific Toolbox or Blockset.
%
% Copyright 2020 NXP
% NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
% accordance with the applicable license terms.  By expressly accepting such terms or by
% downloading, installing, activating and/or otherwise using the software, you are agreeing that
% you have read, and that you agree to comply with and are bound by, such license terms.  If you
% do not agree to be bound by the applicable license terms, then you may not retain, install,
% activate or otherwise use the software.
function blkStruct = slblocks

    blkStruct.Name = ['Automotive Math and Motor Control Library for NXP S32K3xx MCUs' sprintf('\n')]; 
    blkStruct.OpenFcn = 'ammclib_bam_S32K3xx';
    Browser(1).Library = 'ammclib_bam_S32K3xx';
    Browser(1).Name    = 'Automotive Math and Motor Control Library for NXP S32K3xx MCUs';
    Browser(1).IsFlat  = 0;
    Browser(1).Choice  = 1;  % http://www.mathworks.com/matlabcentral/answers/163074-update-library-repository-for-simulink-custom-library
    blkStruct.Browser = Browser;
    
end
