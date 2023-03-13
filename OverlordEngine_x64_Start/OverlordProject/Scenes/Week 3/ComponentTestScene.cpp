//Precompiled Header [ALWAYS ON TOP IN CPP]
#include "stdafx.h"
#include "ComponentTestScene.h"

#include "Prefabs/SpherePrefab.h"

ComponentTestScene::ComponentTestScene()
	: GameScene(L"ComponentTestScene")
{
}

void ComponentTestScene::Initialize()
{
	auto& physx = PxGetPhysics();
	auto pBouncyMaterial = physx.createMaterial(.5f, .5f, 1.f);

	//Ground Plane
	GameSceneExt::CreatePhysXGroundPlane(*this, pBouncyMaterial);

	//RED SPHERE
	const auto pSphereRed = new SpherePrefab(1, 10, XMFLOAT4{ Colors::Red });
	AddChild(pSphereRed);

	pSphereRed->GetTransform()->Translate(0, 30.f, 0);

	auto pRigidBody = pSphereRed->AddComponent(new RigidBodyComponent());
	pRigidBody->AddCollider(PxSphereGeometry{ 1.f }, *pBouncyMaterial);
	pRigidBody->SetCollisionGroup(CollisionGroup::Group0);
	//pRigidBody->SetCollisionIgnoreGroups(CollisionGroup::Group1 | CollisionGroup::Group2);
	pRigidBody->SetConstraint(RigidBodyConstraint::TransX | RigidBodyConstraint::RotZ, false);



	//GREEN SPHERE (GROUP 1)
	const auto pSphereGreen = new SpherePrefab(1, 10, XMFLOAT4{ Colors::Green });
	AddChild(pSphereGreen);

	pSphereGreen->GetTransform()->Translate(0, 20.f, 0);

	pRigidBody = pSphereGreen->AddComponent(new RigidBodyComponent());
	pRigidBody->AddCollider(PxSphereGeometry{ 1.f }, *pBouncyMaterial);
	pRigidBody->SetCollisionGroup(CollisionGroup::Group1);
	pRigidBody->SetConstraint(RigidBodyConstraint::TransX | RigidBodyConstraint::RotZ, false);



	//BLUE SPHERE (GROUP 1)
	const auto pSphereBlue = new SpherePrefab(1, 10, XMFLOAT4{ Colors::Blue });
	AddChild(pSphereBlue);

	pSphereBlue->GetTransform()->Translate(0, 10.f, 0);

	pRigidBody = pSphereBlue->AddComponent(new RigidBodyComponent());
	pRigidBody->AddCollider(PxSphereGeometry{ 1.f }, *pBouncyMaterial);
	pRigidBody->SetCollisionGroup(CollisionGroup::Group2);
	pRigidBody->SetConstraint(RigidBodyConstraint::TransX | RigidBodyConstraint::RotZ, false);



	//m_SceneContext.settings.showInfoOverlay = true;
	//m_SceneContext.settings.drawPhysXDebug = true;
	//m_SceneContext.settings.drawGrid = true;
	//m_SceneContext.settings.enableOnGUI = true;
}
