// Copyright 2016 Michael Noland. Placed under the zlib license.

using UnrealBuildTool;

public class SharedJamUI : ModuleRules
{
	public SharedJamUI(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"SharedJamUI/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"SharedJamUI/Private",
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "UMG"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        bFasterWithoutUnity = true;
	}
}
