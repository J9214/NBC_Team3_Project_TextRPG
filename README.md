- **프로젝트 소개**
    - **프로젝트 이름**
        
        **텍스트 기반 RPG 게임**
        
    - **프로젝트 개요**
        
        이 프로젝트는 **텍스트 기반의 RPG 게임**입니다. 플레이어는 캐릭터를 생성하여 몬스터와 전투하고, 상점에서 아이템을 사고팔며 성장합니다. 주요 콘텐츠는 **전투 시스템, 상점, 아이템 사용, 보스 몬스터**이며, 이를 통해 C++ 객체지향 프로그래밍과 설계 패턴을 학습하고자 하였습니다.
        
    - **주요 기능 요약**
        - **캐릭터 관리**
            - 캐릭터 생성, 레벨업, 체력/공격력/경험치 관리
            - 인벤토리 시스템: 아이템 추가, 사용, 제거
        - **몬스터 전투**
            - 난수 기반 몬스터 생성(Goblin, Orc, Slime, Troll, BossMonster)
            - 플레이어와 몬스터 간 공격 및 피해 계산
            - 전투 종료 조건 및 승리/패배 판정
        - **아이템 시스템**
            - 체력 회복 포션, 공격력 증가 포션 등
            - 다형성을 활용해 확장 가능
        - **보상 및 상점**
            - 경험치, 골드, 아이템 드롭
            - Shop 클래스에서 아이템 구매/판매
        - **게임 흐름 관리**
            - 메인 메뉴, 전투, 상점, 캐릭터 정보 출력
        - **로그**
            - 적 처치 수, 총 획득 골드량, 사용한 아이템 횟수 등 확인 가능
        - **사운드**
            - 배경음악 재생
    - **표준 라이브러리(STL)**
        - `std::vector`: 캐릭터 인벤토리, 상점 아이템 관리
        - `std::string`: 캐릭터/몬스터/아이템 이름 관리
        - **난수 생성**
            - `#include <random>`: 전투 피해, 아이템 드롭, 몬스터 출현 확률 계산
        - **입출력**
            - `#include <iostream>`: 게임 상태 출력 및 사용자 입력 처리
        - **기타**
            - 포인터(`Character*`, `Monster*`, `Item*`) 활용으로 다형성과 동적 메모리 관리
            - `#pragma once`와 헤더 파일 구조화로 코드 모듈화

---

- **개발 환경**
    - **개발 언어 및 도구**
        - **IDE** : Visual Studio 2022
        - **Compiler**: MSVC 14.XX / C++17 이
    - **빌드/실행 방법**
        - **프로젝트 열기**
            - `NBC_Team3_Project_TextRPG.sln` 파일을 더블클릭해서 Visual Studio 실행
        - **빌드 모드 변경**
            - 상단 툴바에서 `Debug` → `Release` 로 변경
        - **실행하기**
            - 메뉴에서 `디버그 → 디버깅하지 않고 시작(Ctrl + F5)`
            - 또는 상단의 **로컬 Windows 디버거** 버튼 클릭
        - **실행 파일 위치 (빌드 완료 후)**
            - `프로젝트폴더/x64/Release/NBC_Team3_Project_TextRPG.exe` 에서 직접 실행 가능
    - **의존 라이브러리/패키지**

- **프로젝트 구조**

```less

MUD_RPG_PROJECT
 ┣ src
 ┃ ┣ Main.cpp                   // 메인 함수 진입점
 ┃ ┣ Character.cpp              // 캐릭터 시스템 구현
 ┃ ┣ Monster.cpp                // 몬스터 부모 클래스 구현
 ┃ ┣ Goblin.cpp                 // 고블린 몬스터 구현
 ┃ ┣ Orc.cpp                    // 오크 몬스터 구현
 ┃ ┣ Slime.cpp                  // 슬라임 몬스터 구현
 ┃ ┣ Troll.cpp                  // 트롤 몬스터 구현
 ┃ ┣ BossMonster.cpp            // 보스 몬스터 구현
 ┃ ┣ Item.cpp                   // 아이템 베이스 클래스 구현
 ┃ ┣ HealthPotion.cpp           // 체력 회복 아이템 구현
 ┃ ┣ AttackBoost.cpp            // 공격력 증가 아이템 구현
 ┃ ┣ Shop.cpp                   // 상점 시스템 구현
 ┃ ┣ GameManager.cpp            // 게임 매니저 (흐름 제어)
 ┃ ┣ BattleSystem.cpp           // 전투 시스템 구현
 ┃ ┣ CharacterStatObserver.cpp  // 전투 로그 시스템 구현
 ┃ ┣ Sound.cpp                  // 사운드 시스템 구현
 ┃
 ┃ ┗ include                   // 헤더 파일 모음
 ┃    ┣ Character.h
 ┃    ┣ Monster.h
 ┃    ┣ Goblin.h
 ┃    ┣ Orc.h
 ┃    ┣ Slime.h
 ┃    ┣ Troll.h
 ┃    ┣ BossMonster.h
 ┃    ┣ Item.h
 ┃    ┣ HealthPotion.h
 ┃    ┣ AttackBoost.h
 ┃    ┣ Shop.h
 ┃    ┣ GameManager.h
 ┃    ┣ BattleSystem.h
 ┃    ┣ CharacterStatObserver.h
 ┃    ┣ Event.h
 ┃    ┣ Sound.h
 ┃               
 ┣ NBC_Team3_Project_TextRPG.sln
 ┗ README.md

```

- **핵심 로직/클래스 설명**
    
    1.  `Character` 클래스 : 플레이어 캐릭터를 관리하는 핵심 클래스입니다.
    
    - **주요 속성**
        - `name`: 캐릭터 이름
        - `level`, `health`, `attack`, `experience`, `gold`: 캐릭터 상태 관리
        - `inventory`: 아이템 보관
    - **주요 함수**
        - `LevelUp()`: 경험치가 일정 수준 이상일 때 레벨업
        - `Attack(Monster&)`: 몬스터 공격
        - `UseItem(int index)`: 아이템 사용
        - `AddItem(Item*)` / `EraseItem(int index)`: 인벤토리 관리
    - **특징**
        - 싱글톤 패턴 지원 (`GetInstance`)으로 플레이어 객체 중복 생성 방지
        - 상태값 보호를 위해 getter/setter 제공
        - 인벤토리 최대 크기 제한
    
    ---
    
    2.  `Monster` 클래스 : 게임 내 몬스터의 기본 구조를 정의하는 추상 클래스입니다.
    
    - **주요 속성**
        - `name`, `level`, `health`, `attack`
    - **주요 함수**
        - `TakeDamage(int)`: 공격 피해 처리
        - `SetHealth`, `SetAttack`: 레벨 기반 능력치 조정
        - `GetHealth`, `GetAttack` : 능력치 반환
        - `RandomBetween(int min, int max)`: 난수 생성
    - **파생 클래스**
        - Goblin, Orc, Slime, Troll, BossMonster
    - **설계 포인트**
        - 추상화된 구조로 새로운 몬스터 추가 시 기존 코드 변경 최소화
        - 레벨과 난수 기반 공격력/체력 조정으로 전투 다양성 확보
    
    ---
    
    3.  `Item` 클래스 및 파생 아이템 : 아이템을 추상화한 클래스와 파생 클래스입니다.
    
    - **주요 속성**
        - `name`, `price`
    - **주요 함수**
        - `Use(Character*)`: 캐릭터에 아이템 효과 적용
        - `Clone()`: 아이템 복사
    - **파생 클래스**
        - `HealthPotion`: 체력 회복
        - `AttackBoost`: 공격력 증가
    - **설계 포인트**
        - 다형성 기반으로 새로운 아이템 확장
        - 프로토타입 패턴을 적용하여 간단한 객체 복사 지원
    
    ---
    
    4.  `GameManager` 클래스 : 게임 흐름과 사용자 인터페이스를 관리합니다.
    
    - **주요 기능**
        - 캐릭터 생성 (`MakeCharacter`)
        - 전투 진행 (`PlayBattle`)
        - 상점 이용 (`ShopEnter`)
        - 캐릭터 정보 출력 (`ShowCharacterInfo`)
        - 메인 메뉴 실행 (`PlayMainMenu`)
    - **설계 포인트**
        - 플레이어, 몬스터, 전투, 상점을 하나의 컨트롤러에서 관리
        - 게임 클리어 조건과 보스 스폰 여부 관리

- **과제 추가 구현 사항 (추가 구현을 했다면 필히 작성!)**
    1. `Shop` 클래스 : 플레이어가 아이템을 구매/판매할 수 있는 상점 시스템입니다.
    - **주요 함수**
        - `DisplayItems()`: 판매 아이템 목록 출력
        - `BuyItem(int, Character*)` / `SellItem(int, Character*)`: 거래 처리
    - **설계 포인트**
        - `Character`와 `Item` 클래스와 연동하여 안전하게 거래 구현
        - 상점 아이템 배열 관리로 확장 용이
    
    ---
    
    1. **보스 몬스터 강화 로직**
        - 기본 몬스터와 차별화를 위해 공격력/체력 범위를 1.5배 확장
        - 동기: 도전 욕구를 주고 클라이맥스를 형성하기 위함
        - 방법 : `RandomBetween(int min, int max)` 함수를 이용해서 난수생성 후 SetHealth와 SetAttack 함수에 변수가 난수의 범위를 조정할 수 있게 하여서 1.5를 대입한 값이 바로 범위로 될 수 있도록 함
    
    ---
    
    1. `BattleSystem` 클래스 : 전투와 관련된 모든 로직을 관리합니다.
    - **주요 함수**
        - `GenerateMonster(int level)`: 플레이어 레벨 기반 몬스터 생성, 레벨 10에서 보스 등장
        - `PlayerAttack(Monster*, Character*)` / `MonsterAttack(Monster*, Character*)`: 전투 처리
        - `Reward(Character*)`: 경험치, 골드, 아이템 보상
        - `UseItem(Character*)`: 아이템 사용
    - **설계 포인트**
        - 난수 기반 전투와 보상 알고리즘으로 반복 플레이에도 긴장감 유지
        - 다형성을 활용한 아이템/몬스터 구조로 코드 확장성
    
    ---
    
    1. `CharacterStatObserver` 클래스: 게임 플레이의 전반적인 로그 관리
    - **주요 함수**
        - `OnNotify(GameEvent event, int value)` : Event type을 인자로 받아 해당 Event에 value를 기록
    - **설계 포인트**
        - Event Type을 Enum Class로 설정하여 어떤 Event가 호출되었는지 한눈에 구별 가능
    
    ---
    
    1. `Sound` 클래스: 사운드와 관련된 로직 처리
    - **주요 함수**
        - `GetInstance()` : Sound 객체를 Return
        - `PlayBGM(const std::string& filePath, float volume)` : filePath에 존재하는 mp3 file을 재생
        - `StopBGM()` : 현재 재생 중인 음악을 종료
    - **설계 포인트**
        - Singleton 패턴을 적용하여 전역적으로 하나의 인스턴스만 존재할 수 있도록 설계
