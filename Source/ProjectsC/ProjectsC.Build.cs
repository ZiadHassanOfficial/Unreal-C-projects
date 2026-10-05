// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectsC : ModuleRules
{
	public ProjectsC(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProjectsC",
			"ProjectsC/Variant_Platforming",
			"ProjectsC/Variant_Platforming/Animation",
			"ProjectsC/Variant_Combat",
			"ProjectsC/Variant_Combat/AI",
			"ProjectsC/Variant_Combat/Animation",
			"ProjectsC/Variant_Combat/Gameplay",
			"ProjectsC/Variant_Combat/Interfaces",
			"ProjectsC/Variant_Combat/UI",
			"ProjectsC/Variant_SideScrolling",
			"ProjectsC/Variant_SideScrolling/AI",
			"ProjectsC/Variant_SideScrolling/Gameplay",
			"ProjectsC/Variant_SideScrolling/Interfaces",
			"ProjectsC/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
