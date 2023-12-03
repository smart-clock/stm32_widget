# smart_clock

# Pin

- D0(PC7) : USART6 RX (ESP32 P05)
- D1(PC6) : USART6 TX (ESP32 P04)
- D2(PG6) : button
- D7(PI3) : buzzer

## Protocol

1. 모든 데이터는 `char` 타입
2. UART BAUDRATE `115200`

### ESP -> STM

| Type   | SOF | P_ID | DATA (ex)                               | EOF  | 설명                                           | 주기        |
| ------ | --- | ---- | --------------------------------------- | ---- | ---------------------------------------------- | ----------- |
| Info   | *   | WF^  | MJU_WIFI                                | '\n' | 연결된 WiFi ID                                 | 부팅 후 1회 |
| Info   | *   | IP^  | 192.168.1.135                           | '\n' | 설정을 위한 ESP32 IP                           | 부팅 후 1회 |
| Info   | *   | BT^  | 78%,01h20m                              | '\n' | 잔량 퍼센트, 남은 시간                         | 1분         |
| Widget | *   | DA^  | 2023-11-21,Mon,07:20:11                 | '\n' | yyyy-mm-dd,day,hh:mm:ss                        | 부팅 후 1회 |
| Widget | *   | WT^  | Yongin,clear sky,25                     | '\n' | 도시, 날씨, 기온                               | 1분         |
| Widget | *   | CA^  | 2,class1,08:00,10:00,class2,13:00,15:00 | '\n' | 일정 개수, 일정, 시각                          | 1일         |
| Widget | *   | BS^  | 5003,명지대 입구,7,20                   | '\n' | 노선 번호, 정류소 이름, 도착 시간1, 도착 시간2 | 30초        |
| Widget | *   | SC^  | AAPL,178.72                             | '\n' | 종목 명, 실시간 주식 가격                      | 1일         |
| Widget | *   | SM^  | AAPL,178.72,179.42,,, 180.31            | '\n' | 종목 명, 주식 가격 일별 22개 (최근 한달 종가)  | 1일         |
| User   | *   | BU^  | 1                                       | '\n' | 버튼 눌림    | Event       |  |

표정렬 : alt + shift + f

## git convention

| Tag Name         | Description                                                                                   |
| ---------------- | --------------------------------------------------------------------------------------------- |
| Feat             | 새로운 기능을 추가                                                                            |
| Fix              | 버그 수정                                                                                     |
| Design           | CSS 등 사용자 UI 디자인 변경                                                                  |
| !BREAKING CHANGE | 커다란 API 변경의 경우                                                                        |
| !HOTFIX          | 급하게 치명적인 버그를 고쳐야하는 경우                                                        |
| Style            | 코드 포맷 변경, 세미 콜론 누락, 코드 수정이 없는 경우                                         |
| Refactor         | 프로덕션 코드 리팩토링                                                                        |
| Comment          | 필요한 주석 추가 및 변경                                                                      |
| Docs             | 문서 수정                                                                                     |
| Test             | 테스트 코드, 리펙토링 테스트 코드 추가, Production Code(실제로 사용하는 코드) 변경 없음       |
| Chore            | 빌드 업무 수정, 패키지 매니저 수정, 패키지 관리자 구성 등 업데이트, Production Code 변경 없음 |
| Rename           | 파일 혹은 폴더명을 수정하거나 옮기는 작업만인 경우                                            |
| Remove           | 파일을 삭제하는 작업만 수행한 경우                                                            |

robot eye

1. happy
2. angry
3. heart
4. bored
5. sad
6. confused
7. blink