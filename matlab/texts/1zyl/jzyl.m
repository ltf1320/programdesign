function varargout = jzyl(varargin)
% JZYL M-file for jzyl.fig
%      JZYL, by itself, creates a new JZYL or raises the existing
%      singleton*.
%
%      H = JZYL returns the handle to a new JZYL or the handle to
%      the existing singleton*.
%
%      JZYL('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in JZYL.M with the given input arguments.
%
%      JZYL('Property','Value',...) creates a new JZYL or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before jzyl_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to jzyl_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help jzyl

% Last Modified by GUIDE v2.5 29-Apr-2012 23:39:11

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @jzyl_OpeningFcn, ...
                   'gui_OutputFcn',  @jzyl_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin & isstr(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before jzyl is made visible.
function jzyl_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to jzyl (see VARARGIN)

% Choose default command line output for jzyl
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes jzyl wait for user response (see UIRESUME)

% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = jzyl_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB`
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in S3.
function S3_Callback(hObject, eventdata, handles)
% hObject    handle to S3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of S3


% --- Executes on button press in S2.
function S2_Callback(hObject, eventdata, handles)
% hObject    handle to S2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of S2


% --- Executes on button press in S1.
function S1_Callback(hObject, eventdata, handles)
% hObject    handle to S1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of S1


% --- Executes on button press in S0.
function S0_Callback(hObject, eventdata, handles)
% hObject    handle to S0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

s0=get(handles.S0,'value');
s1=get(handles.S1,'value');
s2=get(handles.S2,'value');
s3=get(handles.S3,'value');

a0=get(handles.A0,'value');
b0=get(handles.B0,'value');
a1=get(handles.A1,'value');
b1=get(handles.B1,'value');
a2=get(handles.A2,'value');
b2=get(handles.B2,'value');
a3=get(handles.A3,'value');
b3=get(handles.B3,'value');
a4=get(handles.A4,'value');
b4=get(handles.B4,'value');
a5=get(handles.A5,'value');
b5=get(handles.B5,'value');
a6=get(handles.A6,'value');
b6=get(handles.B6,'value');
a7=get(handles.A7,'value');
b7=get(handles.B7,'value');

if s3=0
    if s2=0
        if s1=0
            if s0=0
                


% Hint: get(hObject,'Value') returns toggle state of S0





% --- Executes on button press in LDA.
function LDA_Callback(hObject, eventdata, handles)
% hObject    handle to LDA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
lda=get(handles.LDA,'value');
t4=get(handles.T4,'value');
if lda==1;
    if t4==1;
        set(handles.A0,'value',get(handles.R0,'value'));
        set(handles.A1,'value',get(handles.R1,'value'));
        set(handles.A2,'value',get(handles.R2,'value'));
        set(handles.A3,'value',get(handles.R3,'value'));
        set(handles.A4,'value',get(handles.R4,'value'));
        set(handles.A5,'value',get(handles.R5,'value'));
        set(handles.A6,'value',get(handles.R6,'value'));
        set(handles.A7,'value',get(handles.R7,'value'));
    end
end
    
% Hint: get(hObject,'Value') returns toggle state of LDA


% --- Executes on button press in LDB.
function LDB_Callback(hObject, eventdata, handles)
% hObject    handle to LDB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ldb=get(handles.LDB,'value');
t4=get(handles.T4,'value');
if ldb==1;
    if t4==1;
        set(handles.B0,'value',get(handles.R0,'value'));
        set(handles.B1,'value',get(handles.R1,'value'));
        set(handles.B2,'value',get(handles.R2,'value'));
        set(handles.B3,'value',get(handles.R3,'value'));
        set(handles.B4,'value',get(handles.R4,'value'));
        set(handles.B5,'value',get(handles.R5,'value'));
        set(handles.B6,'value',get(handles.R6,'value'));
        set(handles.B7,'value',get(handles.R7,'value'));
    end
end
% Hint: get(hObject,'Value') returns toggle state of LDB


% --- Executes on button press in ALU1.
function ALU1_Callback(hObject, eventdata, handles)
% hObject    handle to ALU1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ALU1


% --- Executes on button press in R6.
function R6_Callback(hObject, eventdata, handles)
% hObject    handle to R6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R6


% --- Executes on button press in R5.
function R5_Callback(hObject, eventdata, handles)
% hObject    handle to R5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R5


% --- Executes on button press in R4.
function R4_Callback(hObject, eventdata, handles)
% hObject    handle to R4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R4


% --- Executes on button press in R3.
function R3_Callback(hObject, eventdata, handles)
% hObject    handle to R3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R3


% --- Executes on button press in R2.
function R2_Callback(hObject, eventdata, handles)
% hObject    handle to R2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R2



% --- Executes on button press in R0.
function R0_Callback(hObject, eventdata, handles)
% hObject    handle to R0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R0


% --- Executes on button press in R7.
function R7_Callback(hObject, eventdata, handles)
% hObject    handle to R7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R7


% --- Executes on button press in K16.
function K16_Callback(hObject, eventdata, handles)
% hObject    handle to K16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of K16


% --- Executes on button press in K15.
function K15_Callback(hObject, eventdata, handles)
% hObject    handle to K15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of K15


% --- Executes on button press in K14.
function K14_Callback(hObject, eventdata, handles)
% hObject    handle to K14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of K14


% --- Executes on button press in K13.
function K13_Callback(hObject, eventdata, handles)
% hObject    handle to K13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of K13


% --- Executes on button press in K12.
function K12_Callback(hObject, eventdata, handles)
% hObject    handle to K12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of K12


% --- Executes on button press in radiobutton41.
function radiobutton41_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton41 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton41


% --- Executes on button press in radiobutton42.
function radiobutton42_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton42 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton42


% --- Executes on button press in K17.
function K17_Callback(hObject, eventdata, handles)
% hObject    handle to K17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of K17



% --- Executes on button press in ALU2.
function ALU2_Callback(hObject, eventdata, handles)
% hObject    handle to ALU2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ALU2


% --- Executes on button press in CN2.
function CN2_Callback(hObject, eventdata, handles)
% hObject    handle to CN2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of CN2


% --- Executes on button press in ST.
function ST_Callback(hObject, eventdata, handles)
% hObject    handle to ST (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
t3=get(handles.T3,'value');
t4=get(handles.T4,'value');
if t3==1;
    t3=0;
    t4=1;
else 
    if t4==1;
        t4=0;
        t3=0;
    else 
        t3=1;
    end
end
set(handles.T3,'value',t3);
set(handles.T4,'value',t4);

lda=get(handles.LDA,'value');
t4=get(handles.T4,'value');
if lda==1;
    if t4==1;
        set(handles.A0,'value',get(handles.R0,'value'));
        set(handles.A1,'value',get(handles.R1,'value'));
        set(handles.A2,'value',get(handles.R2,'value'));
        set(handles.A3,'value',get(handles.R3,'value'));
        set(handles.A4,'value',get(handles.R4,'value'));
        set(handles.A5,'value',get(handles.R5,'value'));
        set(handles.A6,'value',get(handles.R6,'value'));
        set(handles.A7,'value',get(handles.R7,'value'));
    end
end

ldb=get(handles.LDB,'value');
t4=get(handles.T4,'value');
if lda==1;
    if t4==1;
        set(handles.B0,'value',get(handles.R0,'value'));
        set(handles.B1,'value',get(handles.R1,'value'));
        set(handles.B2,'value',get(handles.R2,'value'));
        set(handles.B3,'value',get(handles.R3,'value'));
        set(handles.B4,'value',get(handles.R4,'value'));
        set(handles.B5,'value',get(handles.R5,'value'));
        set(handles.B6,'value',get(handles.R6,'value'));
        set(handles.B7,'value',get(handles.R7,'value'));
    end
end
% --- Executes on button press in T3.
function T3_Callback(hObject, eventdata, handles)
% hObject    handle to T3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of T3


% --- Executes on button press in T4.
function T4_Callback(hObject, eventdata, handles)
% hObject    handle to T4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of T4


% --- Executes on button press in R1.
function R1_Callback(hObject, eventdata, handles)
% hObject    handle to R1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of R1


% --- Executes on button press in CLS.
function CLS_Callback(hObject, eventdata, handles)
% hObject    handle to CLS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.K1,'String','');
set(handles.K2,'String','');
set(handles.CPU,'Stding','');
set(handles.FC,'value',0);
set(handles.FZ,'value',0);

% --- Executes during object creation, after setting all properties.
function K1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to K1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function K1_Callback(hObject, eventdata, handles)
% hObject    handle to K1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of K1 as text
%        str2double(get(hObject,'String')) returns contents of K1 as a double


% --- Executes during object creation, after setting all properties.
function K2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to K2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function K2_Callback(hObject, eventdata, handles)
% hObject    handle to K2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of K2 as text
%        str2double(get(hObject,'String')) returns contents of K2 as a double


% --- Executes during object creation, after setting all properties.
function CPU_CreateFcn(hObject, eventdata, handles)
% hObject    handle to CPU (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function CPU_Callback(hObject, eventdata, handles)
% hObject    handle to CPU (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of CPU as text
%        str2double(get(hObject,'String')) returns contents of CPU as a double


% --- Executes on button press in FC.
function FC_Callback(hObject, eventdata, handles)
% hObject    handle to FC (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of FC


% --- Executes on button press in FZ.
function FZ_Callback(hObject, eventdata, handles)
% hObject    handle to FZ (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of FZ


% --- Executes on button press in A6.
function A6_Callback(hObject, eventdata, handles)
% hObject    handle to A6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A6


% --- Executes on button press in A5.
function A5_Callback(hObject, eventdata, handles)
% hObject    handle to A5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A5


% --- Executes on button press in A4.
function A4_Callback(hObject, eventdata, handles)
% hObject    handle to A4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A4


% --- Executes on button press in A3.
function A3_Callback(hObject, eventdata, handles)
% hObject    handle to A3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A3


% --- Executes on button press in A2.
function A2_Callback(hObject, eventdata, handles)
% hObject    handle to A2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A2


% --- Executes on button press in A1.
function A1_Callback(hObject, eventdata, handles)
% hObject    handle to A1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A1


% --- Executes on button press in A0.
function A0_Callback(hObject, eventdata, handles)
% hObject    handle to A0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A0


% --- Executes on button press in A7.
function A7_Callback(hObject, eventdata, handles)
% hObject    handle to A7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of A7


% --- Executes on button press in B6.
function B6_Callback(hObject, eventdata, handles)
% hObject    handle to B6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B6


% --- Executes on button press in B5.
function B5_Callback(hObject, eventdata, handles)
% hObject    handle to B5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B5


% --- Executes on button press in B4.
function B4_Callback(hObject, eventdata, handles)
% hObject    handle to B4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B4


% --- Executes on button press in B3.
function B3_Callback(hObject, eventdata, handles)
% hObject    handle to B3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B3


% --- Executes on button press in B2.
function B2_Callback(hObject, eventdata, handles)
% hObject    handle to B2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B2


% --- Executes on button press in B1.
function B1_Callback(hObject, eventdata, handles)
% hObject    handle to B1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B1


% --- Executes on button press in B0.
function B0_Callback(hObject, eventdata, handles)
% hObject    handle to B0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B0


% --- Executes on button press in B7.
function B7_Callback(hObject, eventdata, handles)
% hObject    handle to B7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of B7


% --- Executes on button press in D6.
function D6_Callback(hObject, eventdata, handles)
% hObject    handle to D6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D6


% --- Executes on button press in D5.
function D5_Callback(hObject, eventdata, handles)
% hObject    handle to D5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D5


% --- Executes on button press in D4.
function D4_Callback(hObject, eventdata, handles)
% hObject    handle to D4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D4


% --- Executes on button press in D3.
function D3_Callback(hObject, eventdata, handles)
% hObject    handle to D3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D3


% --- Executes on button press in D2.
function D2_Callback(hObject, eventdata, handles)
% hObject    handle to D2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D2


% --- Executes on button press in D1.
function D1_Callback(hObject, eventdata, handles)
% hObject    handle to D1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D1


% --- Executes on button press in D0.
function D0_Callback(hObject, eventdata, handles)
% hObject    handle to D0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D0


% --- Executes on button press in D7.
function D7_Callback(hObject, eventdata, handles)
% hObject    handle to D7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of D7


