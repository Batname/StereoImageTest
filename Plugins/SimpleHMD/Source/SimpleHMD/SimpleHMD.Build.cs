// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class SimpleHMD : ModuleRules
	{
		public SimpleHMD(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateIncludePaths.AddRange(
				new string[] {
                    "SimpleHMD/Private",
				}
			);

            PublicIncludePaths.AddRange(
				new string[] {
					"SimpleHMD/Private",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "RHI",
                    "RenderCore",
                    "UtilityShaders",
                    "Renderer",
                    "ShaderCore",
                    "InputCore",
                    "HeadMountedDisplay",
                    "Slate",
                    "SlateCore",
                    "UMG"
                }
				);
		}
	}
}
