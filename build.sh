#!/bin/bash

ANDROID_HOME="/Users/lixiaochen/Library/Android/sdk"
BUILD_TOOLS_VERSION="25.0.2"
dx=${ANDROID_HOME}/build-tools/${BUILD_TOOLS_VERSION}/dx

ROOT=${PWD}
classpath=${ROOT}/app/build/intermediates/classes/debug/brian/com/nativehotfixdemo/hotfix/ArrayUtils.class
assets=${ROOT}/app/src/main/assets

WORK_DIR=${ROOT}/app/src/main/java
des="brian/com/nativehotfixdemo/hotfix"

rm ${des}/*.class
rm ${assets}/hotfix.dex

cd ${WORK_DIR}
cp ${classpath} ${des}

${dx} --dex --output=${assets}/hotfix.dex ${des}/*.class

cd ${ROOT}