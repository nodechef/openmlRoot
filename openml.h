#include <jni.h>
#include <iostream>
#include <string>
#include "TObject.h"


class openml : public TObject {

   private:
	JavaVM *jvm;				// Pointer to the JVM (Java Virtual Machine)
	JNIEnv *env;				// Pointer to native interface
		//==================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options 				// JVM invocation options


	//================= load and initialize Java VM and JNI interface ===============
	jint rc;  // YES !!
	
	jint ver;
	// First call to JAVA ==================================================================
	jclass cls2;

      Float_t   fX;         //x position in centimeters
      Float_t   fY;         //y position in centimeters
      Int_t     fTempValue; //! temporary state value


   public:

	openml(){ 
		options = new JavaVMOption[1];   // JVM invocation options		
		options[0].optionString = "-Djava.class.path=./classes/lib/*.jar";
		options[0].optionString = "-Djava.class.path=./classes/openml.jar";   // where to find java .class
		vm_args.version = JNI_VERSION_1_6;             // minimum Java version
		vm_args.nOptions = 1;                          // number of options
		vm_args.options = options;
		vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
		
		//================= load and initialize Java VM and JNI interface ===============
		rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
		
		delete options;    // we then no longer need the initialisation options. 

			   //========================= analyse errors if any  ==============================
			   // if process interuped before error is returned, it's because jvm.dll can't be 
			   // found, i.e.  its directory is not in the PATH. 

		if (rc != JNI_OK) {
			if (rc == JNI_EVERSION)
				cerr << "FATAL ERROR: JVM is oudated and doesn't meet requirements" << endl;
			else if (rc == JNI_ENOMEM)
				cerr << "FATAL ERROR: not enough memory for JVM" << endl;
			else if (rc == JNI_EINVAL)
				cerr << "FATAL ERROR: invalid ragument for launching JVM" << endl;
			else if (rc == JNI_EEXIST)
				cerr << "FATAL ERROR: the process can only launch one JVM an not more" << endl;
			else
				cerr << "FATAL ERROR:  could not create the JVM instance (error code " << rc << ")" << endl;
			cin.get();
			exit(EXIT_FAILURE);
		}

		cout << "JVM load succeeded. \nVersion ";
		ver = env->GetVersion();
		cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

		// First call to JAVA ==================================================================
		cls2 = env->FindClass("com/openml/openml/mvn/main");  // try to find the class 

		if (cls2 == nullptr) {
			cerr << "ERROR: class not found !";
		}
		else {                                  // if class found, continue
			cout << "Class Main found" << endl;
		}
	}
      

	void dataSetList();
	void downloadDataSet(int id);
	void datasetFeatures(int id);
	void uploadDataSet(string dataSetName, string dataSetDescription, string filename);
	void uploadDataSetUrl(string dataSetName, string dataSetDescription, string dataUrl);
	void flowDescription(int id);
	void flowsExists(string flowCheckName, string flowCheckVersion);
	void Removeflow(int flowIDRemove);
	void uploadFlow(string flowDescription, string CodeJar, string sourceZip);
	void taskDescription(int id);
	void taskEvaluations();
	void runDescription(int id);
	void runDelete(int id);
	void runUpload(string firstTag, string secondTag, string filename);
	
	~openml();

	ClassDef(openml, 1)


};
