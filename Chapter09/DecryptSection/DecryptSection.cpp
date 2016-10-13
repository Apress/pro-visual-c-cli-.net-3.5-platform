using namespace System;
using namespace System::Configuration;
using namespace System::IO;

void DecryptConfigurationSection(String^ sectionName)  
{  
    String^ tmpPath = Reflection::Assembly::GetExecutingAssembly()->Location;
	String^ exePath = Path::GetDirectoryName(tmpPath) + "\\EncryptSection.exe";

    System::Configuration::Configuration^ config =
        ConfigurationManager::OpenExeConfiguration(exePath);

    ConfigurationSection^ section = config->GetSection(sectionName);

    if (section->SectionInformation->IsProtected)  
    {   
        section->SectionInformation->UnprotectSection(); 
        section->SectionInformation->ForceSave = true;
        config->Save();   
    }  
} 

String^ DumpConfig()
{
    String^ tmpPath = Reflection::Assembly::GetExecutingAssembly()->Location;
	String^ path = Path::GetDirectoryName(tmpPath) + "\\EncryptSection.exe.config";

    StreamReader^ sr = File::OpenText(path);
    String^ ret = sr->ReadToEnd();
    sr->Close();

    return ret; 
}

int main(array<System::String ^> ^args)
{
    Console::WriteLine("*** Before Encryption:\n{0}\n\n", DumpConfig());

    DecryptConfigurationSection("appSettings");
    Console::WriteLine("*** After Decryption:\n{0}\n\n", DumpConfig());

    return 0;
}
