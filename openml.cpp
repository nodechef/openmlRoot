#include <jni.h>
#include <iostream>
#include <string>
#include "TObject.h"
#include "openml.h"


ClassImp(openml)

void openml::dataSetList(){

	jmethodID mid2 = env->GetStaticMethodID(cls2, "dataSetList", "()V");
	env->CallStaticVoidMethod(cls2, mid2);
}



void openml::downloadDataSet(int id){
	
	jmethodID mid2 = env->GetStaticMethodID(cls2, "datasetDownload", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)id);   

}

void openml::datasetFeatures(int id){

	jmethodID mid2 = env->GetStaticMethodID(cls2, "datasetFeatures", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)id);   

}


void openml::uploadDataSet(string dataSetName, string dataSetDescription, string filename){
	jstring jStringParam1 = env->NewStringUTF(dataSetName.c_str());
	jstring jStringParam2 = env->NewStringUTF(dataSetDescription.c_str());
	jstring jStringParam3 = env->NewStringUTF(filename.c_str());
	jmethodID mid2 = env->GetStaticMethodID(cls2, "upload", "(Ljava/lang/String;Ljava/langString;Ljava/lang/String;)V");
	env->CallStaticVoidMethod(cls2, mid2, jStringParam1, jStringParam2, jStringParam3);
	env->DeleteLocalRef(jStringParam1);
	env->DeleteLocalRef(jStringParam2);
	env->DeleteLocalRef(jStringParam3);   
}


void openml::uploadDataSetUrl(string dataSetName, string dataSetDescription, string dataUrl){

	jstring jStringParam1 = env->NewStringUTF(dataSetName.c_str());
	jstring jStringParam2 = env->NewStringUTF(dataSetDescription.c_str());
	jstring jStringParam3 = env->NewStringUTF(dataUrl.c_str());
	jmethodID mid2 = env->GetStaticMethodID(cls2, "uploadURL", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	env->CallStaticVoidMethod(cls2, mid2, jStringParam1, jStringParam2, jStringParam3);
	env->DeleteLocalRef(jStringParam1);
	env->DeleteLocalRef(jStringParam2);
	env->DeleteLocalRef(jStringParam3);

}


void openml::flowDescription(int id){
	
	jmethodID mid2 = env->GetStaticMethodID(cls2, "flowDescription", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)flowID);   

}


void openml::flowsExists(string flowCheckName, string flowCheckVersion){
	jstring jStringParam1 = env->NewStringUTF(flowCheckName.c_str());
	jstring jStringParam2 = env->NewStringUTF(flowCheckVersion.c_str());
	jmethodID mid2 = env->GetStaticMethodID(cls2, "flowsExists", "(Ljava/lang/String;Ljava/lang/String;)V");
	env->CallStaticVoidMethod(cls2, mid2, jStringParam1, jStringParam2);
	env->DeleteLocalRef(jStringParam1);
	env->DeleteLocalRef(jStringParam2);   
}



void openml::Removeflow(int flowIDRemove){
	
	jmethodID mid2 = env->GetStaticMethodID(cls2, "Removeflow", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)flowIDRemove);   

}
void openml::uploadFlow(string flowDescription, string CodeJar, string sourceZip){

	jstring jStringParam1 = env->NewStringUTF(flowDescription.c_str());
	jstring jStringParam2 = env->NewStringUTF(CodeJar.c_str());
	jstring jStringParam3 = env->NewStringUTF(sourceZip.c_str());
	jmethodID mid2 = env->GetStaticMethodID(cls2, "Uploadflow", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	env->CallStaticVoidMethod(cls2, mid2, jStringParam1, jStringParam2, jStringParam3);
	env->DeleteLocalRef(jStringParam1);
	env->DeleteLocalRef(jStringParam2);
	env->DeleteLocalRef(jStringParam3);
   
}
void openml::taskDescription(int id){
	jmethodID mid2 = env->GetStaticMethodID(cls2, "taskDescription", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)id);   
}


void openml::taskEvaluations(){

	jmethodID mid2 = env->GetStaticMethodID(cls2, "taskEvaluations", "()V");
	env->CallStaticVoidMethod(cls2, mid2);   

}
void openml::runDescription(int id){

	// Check out and try this function in Java.And print result
	jmethodID mid2 = env->GetStaticMethodID(cls2, "runDescription", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)id);   

}
void openml::runDelete(int id){
	
	jmethodID mid2 = env->GetStaticMethodID(cls2, "runDelete", "(I)V");
	env->CallStaticVoidMethod(cls2, mid2, (jint)id);   

}
void openml::runUpload(string firstTag, string secondTag, string filename){
	
	jstring jStringParam1 = env->NewStringUTF(firstTag.c_str());
	jstring jStringParam2 = env->NewStringUTF(secondTag.c_str());
	jstring jStringParam3 = env->NewStringUTF(filename.c_str());
	jmethodID mid2 = env->GetStaticMethodID(cls2, "runUpload", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	env->CallStaticVoidMethod(cls2, mid2, jStringParam1, jStringParam2, jStringParam3);
	env->DeleteLocalRef(jStringParam1);
	env->DeleteLocalRef(jStringParam2);
	env->DeleteLocalRef(jStringParam3);

}

~openml(){
	jvm->DestroyJavaVM();
}
