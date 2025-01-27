#include "HelloWorldActor.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Constructor
AHelloWorldActor::AHelloWorldActor()
{
    // Enable ticking
    PrimaryActorTick.bCanEverTick = true; 
}

// Called when the game starts or when spawned
void AHelloWorldActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AHelloWorldActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Draw "HELLO WORLD" starting from the center
    DrawHelloWorldLogo(FVector(0, 0, 100)); // Adjust Z for visibility
}

void AHelloWorldActor::DrawHelloWorldLogo(FVector StartLocation)
{
    // Width of each letter
    const float LetterWidth = 50.0f;  
    // Height of each letter
    const float LetterHeight = 100.0f; 
    // Space between letters
    const float LetterSpacing = 10.0f; 
    // Space between words
    const float WordSpacing = 30.0f;   
    FVector CurrentLocation = StartLocation;

    // Lambda functions for each letter
    auto DrawLetterH = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, 0, RotationAngle);
            FRotationMatrix RotationMatrix(Rotation);

            FVector TopLeft = RotationMatrix.TransformPosition(FVector(0, LetterHeight / 2, 0));
            FVector BottomLeft = RotationMatrix.TransformPosition(FVector(0, -LetterHeight / 2, 0));
            FVector TopRight = RotationMatrix.TransformPosition(FVector(0, LetterHeight / 2, LetterWidth));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(0, -LetterHeight / 2, LetterWidth));
            FVector MiddleLeft = RotationMatrix.TransformPosition(FVector(0, 0, 0));
            FVector MiddleRight = RotationMatrix.TransformPosition(FVector(0, 0, LetterWidth));

            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + BottomLeft, FColor::Red, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopRight, Loc + BottomRight, FColor::Red, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + MiddleLeft, Loc + MiddleRight, FColor::Red, false, -1, 0, 5.0f);
        };


    auto DrawLetterE = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, RotationAngle, 0);
            FRotationMatrix RotationMatrix(Rotation);

            FVector Top = RotationMatrix.TransformPosition(FVector(0, 0, LetterHeight / 2));
            FVector Bottom = RotationMatrix.TransformPosition(FVector(0, 0, -LetterHeight / 2));
            FVector TopRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, LetterHeight / 2));
            FVector MiddleRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, 0));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, -LetterHeight / 2));
            FVector Middle = RotationMatrix.TransformPosition(FVector(0, 0, 0));

            DrawDebugLine(GetWorld(), Loc + Top, Loc + Bottom, FColor::Green, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + Top, Loc + TopRight, FColor::Green, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + Middle, Loc + MiddleRight, FColor::Green, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + Bottom, Loc + BottomRight, FColor::Green, false, -1, 0, 5.0f);
        };


    auto DrawLetterL = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, RotationAngle, 0);
            FRotationMatrix RotationMatrix(Rotation);

            FVector Top = RotationMatrix.TransformPosition(FVector(0, 0, LetterHeight / 2));
            FVector Bottom = RotationMatrix.TransformPosition(FVector(0, 0, -LetterHeight / 2));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, -LetterHeight / 2));

            DrawDebugLine(GetWorld(), Loc + Top, Loc + Bottom, FColor::Blue, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + Bottom, Loc + BottomRight, FColor::Blue, false, -1, 0, 5.0f);
        };

    auto DrawLetterO = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, RotationAngle, 0);
            FRotationMatrix RotationMatrix(Rotation);

            FVector TopLeft = RotationMatrix.TransformPosition(FVector(0, 0, LetterHeight / 2));
            FVector BottomLeft = RotationMatrix.TransformPosition(FVector(0, 0, -LetterHeight / 2));
            FVector TopRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, LetterHeight / 2));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, -LetterHeight / 2));

            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + BottomLeft, FColor::Yellow, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + TopRight, FColor::Yellow, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopRight, Loc + BottomRight, FColor::Yellow, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + BottomLeft, Loc + BottomRight, FColor::Yellow, false, -1, 0, 5.0f);
        };

    auto DrawLetterW = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, RotationAngle, 0);
            FRotationMatrix RotationMatrix(Rotation);

            FVector TopLeft = RotationMatrix.TransformPosition(FVector(0, 0, LetterHeight / 2));
            FVector BottomLeft = RotationMatrix.TransformPosition(FVector(0, 0, -LetterHeight / 2));
            FVector MiddleLeft = RotationMatrix.TransformPosition(FVector(LetterWidth / 2, 0, -LetterHeight / 4));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, -LetterHeight / 2));
            FVector TopRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, LetterHeight / 2));

            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + BottomLeft, FColor::Cyan, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + BottomLeft, Loc + MiddleLeft, FColor::Cyan, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + MiddleLeft, Loc + BottomRight, FColor::Cyan, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + BottomRight, Loc + TopRight, FColor::Cyan, false, -1, 0, 5.0f);
        };

    auto DrawLetterR = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, RotationAngle, 0);
            FRotationMatrix RotationMatrix(Rotation);

            FVector TopLeft = RotationMatrix.TransformPosition(FVector(0, 0, LetterHeight / 2));
            FVector BottomLeft = RotationMatrix.TransformPosition(FVector(0, 0, -LetterHeight / 2));
            FVector TopRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, LetterHeight / 2));
            FVector MiddleRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, 0));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, -LetterHeight / 2));
            FVector MiddleLeft = RotationMatrix.TransformPosition(FVector(0, 0, 0));

            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + BottomLeft, FColor::Magenta, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + TopRight, FColor::Magenta, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopRight, Loc + MiddleRight, FColor::Magenta, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + MiddleRight, Loc + MiddleLeft, FColor::Magenta, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + MiddleLeft, Loc + BottomRight, FColor::Magenta, false, -1, 0, 5.0f);
        };

    auto DrawLetterD = [&](FVector Loc, float RotationAngle)
        {
            FRotator Rotation(0, RotationAngle, 0);
            FRotationMatrix RotationMatrix(Rotation);

            FVector TopLeft = RotationMatrix.TransformPosition(FVector(0, 0, LetterHeight / 2));
            FVector BottomLeft = RotationMatrix.TransformPosition(FVector(0, 0, -LetterHeight / 2));
            FVector TopRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, LetterHeight / 2));
            FVector BottomRight = RotationMatrix.TransformPosition(FVector(LetterWidth, 0, -LetterHeight / 2));

            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + BottomLeft, FColor::Orange, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopLeft, Loc + TopRight, FColor::Orange, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + TopRight, Loc + BottomRight, FColor::Orange, false, -1, 0, 5.0f);
            DrawDebugLine(GetWorld(), Loc + BottomLeft, Loc + BottomRight, FColor::Orange, false, -1, 0, 5.0f);
        };

    // Draw "HELLO" with different rotations
    DrawLetterH(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterE(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterL(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterL(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterO(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + WordSpacing;

    // Draw "WORLD"
    DrawLetterW(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterO(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterR(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterL(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
    DrawLetterD(CurrentLocation, 90); CurrentLocation.Y += LetterWidth + LetterSpacing;
}
