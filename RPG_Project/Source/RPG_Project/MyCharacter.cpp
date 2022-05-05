// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter() // Awake
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.f, 0.0f, 0.0f));

	// 유연성을 결정하기 위한 전용 변수들
	OurCameraSpringArm->TargetArmLength = 400.0f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);

	// 기본 플레이어의 제어권을 획득한다.
	AutoPossessPlayer = EAutoReceiveInput::Player0; // 가장 빠른 번호의 플레이어가 조종함
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// "ZoomIn" 에 대한 이벤트
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AMyCharacter::ZoomIn);
	InputComponent->BindAction("ZoomIn", IE_Released, this, &AMyCharacter::ZoomOut);
	//InputComponent->BindAction("ViewChange", IE_Pressed, this, &AMyCharacter::ViewChange);

	// 네 축에 대한 매 프레임 처리
	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &AMyCharacter::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AMyCharacter::YawCamera);

	if (bZoomingln)
	{
		ZoomFactor += DeltaTime / 0.5f; // 0.5 초에 걸려 줌인

	}
	else
	{
		ZoomFactor -= DeltaTime / 0.25f; // 0.25 초에 걸려 줌아웃
	}
	ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);

	// ZoomFactor 에 따라 스프링 암의 길이와 카메라의 시야 블렌딩
	OurCamera->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
	OurCameraSpringArm->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, ZoomFactor);



	// 엑터의 Yaw를 회전, 붙어있는 카메라도 따라서 회전된다.
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation);
	}

	// 카메라의 피치를 회전하지만, 항상 아래를 보도록 제한시킨다.
	 {
		FRotator NewRotation = OurCameraSpringArm->GetComponentRotation(); // NewRotation_SpringArm
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f, -15.0f); // 카메라 Pitch 최대 고정
		OurCameraSpringArm->SetWorldRotation(NewRotation);
	}
	// "MoveX" 와 "MoveY" 축에 따라 이동을 처리한다.
	// 액터나 그 서브클래스를 회전시키면 실제로 루트 레벨의 컴포넌트가 회전되어, 붙어있는 모든 것에 간접적으로 영향을 끼친다.


	/*
	if (MovementInput.IsZero() && isSpin)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spin?"));
		// 이동 입력 축 값에 초당 100 유닛 스케일을 적용합니다

		MovementInput = MovementInput.GetSafeNormal() * 100.0f;
		FVector NewLocation = GetActorLocation();
		// GetActor~Vector 를 사용하면 액터가 향하는 방향을 기준으로 이동하는 것이 가능하다. 카메라와 엑터가 같은 쪽을 향하고 있기 때문에,
		// 전방 키가 항상 플레이어가 바라보는 것을 기준으로 앞이 되도록 해준다.
		NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
		NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
		SetActorLocation(NewLocation);
	}*/
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMyCharacter::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}
void AMyCharacter::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}
void AMyCharacter::ZoomIn()
{
	bZoomingln = true;
}
void AMyCharacter::ZoomOut()
{
	bZoomingln = false;
}
void AMyCharacter::MoveForward(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector WorldDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(WorldDirection, AxisValue);
}
void AMyCharacter::MoveRight(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector WorldDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(WorldDirection, AxisValue);
}
