### **Git 태그 명령어**

| **명령어** | **설명** |
|------------|---------|
| `git tag` | 로컬 저장소의 태그 목록 확인 |
| `git tag -n` | 태그 목록을 설명과 함께 표시 |
| `git tag -l "v1.*"` | 특정 패턴(`v1.*`)에 맞는 태그 목록 검색 |
| `git tag --sort=-creatordate` | 태그를 최신순으로 정렬하여 출력 |
| `git tag -a <tagname> -m "설명"` | 주석(Annotated) 태그 생성 |
| `git tag <tagname>` | 경량(Lightweight) 태그 생성 |
| `git tag -a <tagname> <커밋해시> -m "설명"` | 특정 커밋에 주석 태그 추가 |
| `git show <tagname>` | 특정 태그의 상세 정보 확인 |
| `git tag -d <tagname>` | 로컬 태그 삭제 |
| `git push origin --delete <tagname>` | 원격 저장소에서 태그 삭제 |
| `git push origin <tagname>` | 특정 태그를 원격 저장소로 푸시 |
| `git push --tags` | 로컬의 모든 태그를 원격 저장소로 푸시 |
| `git checkout tags/<tagname>` | 특정 태그로 이동 (읽기 전용) |
| `git checkout -b <새로운브랜치> tags/<tagname>` | 태그에서 새 브랜치 생성 |
| `git clone --branch <tagname> --depth 1 <저장소URL>` | 특정 태그만 클론 (shallow clone) |
| `git clone <저장소URL>` → `git checkout tags/<tagname>` | 전체 저장소 클론 후 특정 태그로 이동 |
| `git fetch --tags` | 원격 저장소의 최신 태그 가져오기 |
| `git tag --contains <커밋해시>` | 특정 커밋이 포함된 태그 목록 확인 |
| `git tag --points-at HEAD` | 현재 커밋(HEAD)에 붙어 있는 태그 확인 |
