using namespace System;
using namespace System::Configuration;
using namespace System::IO;

void EncryptConfigurationSection(String^ sectionName, String^ Provider)   
{
    String^ exePath = Reflection::Assembly::GetExecutingAssembly()->Location;
        
    System::Configuration::Configuration^ config =
        ConfigurationManager::OpenExeConfiguration(exePath);

    ConfigurationSection^ section = config->GetSection(sectionName);
  
    if (!section->SectionInformation->IsProtected)  
    {   
        section->SectionInformation->ProtectSection(Provider);   
        section->SectionInformation->ForceSave = true;   
        config->Save();   
    } 
}  

String^ DumpConfig()
{
    String^ path = 
        Reflection::Assembly::GetExecutingAssembly()->Location + ".config";

    StreamReader^ sr = File::OpenText(path);
    String^ ret = sr->ReadToEnd();
    sr->Close();

    return ret; 
}

int main(array<System::String ^> ^args)
{
//    String^ EncryptProvider = "RsaProtectedConfigurationProvider";
	String^ EncryptProvider = "DataProtectionConfigurationProvider";

    Console::WriteLine("*** Before Encryption:\n{0}\n\n", DumpConfig());

    EncryptConfigurationSection("appSettings", EncryptProvider);
    Console::WriteLine("*** After Encryption:\n{0}\n\n", DumpConfig());

	return 0;
}
