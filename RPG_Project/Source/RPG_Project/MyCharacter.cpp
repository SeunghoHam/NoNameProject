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

	// �������� �����ϱ� ���� ���� ������
	OurCameraSpringArm->TargetArmLength = 400.0f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);

	// �⺻ �÷��̾��� ������� ȹ���Ѵ�.
	AutoPossessPlayer = EAutoReceiveInput::Player0; // ���� ���� ��ȣ�� �÷��̾ ������
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
	// "ZoomIn" �� ���� �̺�Ʈ
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AMyCharacter::ZoomIn);
	InputComponent->BindAction("ZoomIn", IE_Released, this, &AMyCharacter::ZoomOut);
	//InputComponent->BindAction("ViewChange", IE_Pressed, this, &AMyCharacter::ViewChange);

	// �� �࿡ ���� �� ������ ó��
	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &AMyCharacter::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AMyCharacter::YawCamera);

	if (bZoomingln)
	{
		ZoomFactor += DeltaTime / 0.5f; // 0.5 �ʿ� �ɷ� ����

	}
	else
	{
		ZoomFactor -= DeltaTime / 0.25f; // 0.25 �ʿ� �ɷ� �ܾƿ�
	}
	ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);

	// ZoomFactor �� ���� ������ ���� ���̿� ī�޶��� �þ� ����
	OurCamera->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
	OurCameraSpringArm->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, ZoomFactor);



	// ������ Yaw�� ȸ��, �پ��ִ� ī�޶� ���� ȸ���ȴ�.
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation);
	}

	// ī�޶��� ��ġ�� ȸ��������, �׻� �Ʒ��� ������ ���ѽ�Ų��.
	 {
		FRotator NewRotation = OurCameraSpringArm->GetComponentRotation(); // NewRotation_SpringArm
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f, -15.0f); // ī�޶� Pitch �ִ� ����
		OurCameraSpringArm->SetWorldRotation(NewRotation);
	}
	// "MoveX" �� "MoveY" �࿡ ���� �̵��� ó���Ѵ�.
	// ���ͳ� �� ����Ŭ������ ȸ����Ű�� ������ ��Ʈ ������ ������Ʈ�� ȸ���Ǿ�, �پ��ִ� ��� �Ϳ� ���������� ������ ��ģ��.


	/*
	if (MovementInput.IsZero() && isSpin)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spin?"));
		// �̵� �Է� �� ���� �ʴ� 100 ���� �������� �����մϴ�

		MovementInput = MovementInput.GetSafeNormal() * 100.0f;
		FVector NewLocation = GetActorLocation();
		// GetActor~Vector �� ����ϸ� ���Ͱ� ���ϴ� ������ �������� �̵��ϴ� ���� �����ϴ�. ī�޶�� ���Ͱ� ���� ���� ���ϰ� �ֱ� ������,
		// ���� Ű�� �׻� �÷��̾ �ٶ󺸴� ���� �������� ���� �ǵ��� ���ش�.
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
