set workdir=D:\\projects\\NativeHotFixDemo\\app\\src\\main\\java\\
set dx=D:\\tools\\AndroidSdk\\build-tools\\25.0.2\\dx
set src=D:\\projects\\NativeHotFixDemo\\app\\build\\intermediates\\classes\\debug\\brian\\com\\nativehotfixdemo\\hotfix\\ArrayUtils.class
set des=brian\\com\\nativehotfixdemo\\hotfix\\
set output=brian\com\\nativehotfixdemo\\hotfix\\hotfix.dex
set output=..\\assets\\hotfix.dex

cd %workdir%

del %des%*.dex
del %des%*.class
del %output%

copy %src% %des%

%dx% --dex --output=%output% %des%*

