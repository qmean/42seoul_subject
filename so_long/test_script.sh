#!/bin/bash

# maps 디렉토리가 없으면 생성
if [ ! -d "maps" ]; then
	mkdir maps
fi

# 맵을 넣어주지 않은 경우
./so_long
echo "맵을 넣어주지 않은 경우 테스트 완료"

# 맵을 여러개 넣은 경우
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P000001\n1000000001\n10C000C001\n1000000001\n10E0000001\n1111111111" > maps/map1.ber
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P000001\n1000000001\n10C000C001\n1000000001\n10E0000001\n1111111111" > maps/map2.ber
./so_long maps/map1.ber maps/map2.ber
echo "맵을 여러개 넣은 경우 테스트 완료"

# 맵 이름이 이상할 경우 (확장자가 .ber가 아닌 경우)
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P000001\n1000000001\n10C000C001\n1000000001\n10E0000001\n1111111111" > maps/strange_name.txt
./so_long maps/strange_name.txt
echo "맵 이름이 이상한 경우 테스트 완료"

# 없는 맵을 넣어준 경우
./so_long maps/nonexistent.ber
echo "없는 맵을 넣어준 경우 테스트 완료"

# 출구가 여러개인 경우
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P000001\n1000000001\n10C000C001\n1000000001\n10E000E001\n1111111111" > maps/multiple_exits.ber
./so_long maps/multiple_exits.ber
echo "출구가 여러개인 경우 테스트 완료"

# 코인이 하나도 없을 경우
echo -e "1111111111\n1000000001\n1000000001\n1000000001\n100P000001\n1000000001\n1000000001\n1000000001\n10E0000001\n1111111111" > maps/no_coins.ber
./so_long maps/no_coins.ber
echo "코인이 하나도 없을 경우 테스트 완료"

# 출구가 하나도 없을 경우
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P000001\n1000000001\n10C000C001\n1000000001\n1000000001\n1111111111" > maps/no_exits.ber
./so_long maps/no_exits.ber
echo "출구가 하나도 없을 경우 테스트 완료"

# 플레이어가 없을 경우
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n1000000001\n1000000001\n10C000C001\n1000000001\n10E0000001\n1111111111" > maps/no_player.ber
./so_long maps/no_player.ber
echo "플레이어가 없을 경우 테스트 완료"

# 플레이어가 여러개인 경우
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P000001\n100P000001\n10C000C001\n1000000001\n10E0000001\n1111111111" > maps/multiple_players.ber
./so_long maps/multiple_players.ber
echo "플레이어가 여러개인 경우 테스트 완료"

# 벽에 막혀서 모든 코인을 줍지 못하거나 출구로 갈 수 없는 상황
echo -e "1111111111\n1000000001\n10C000C001\n1000000001\n100P1111001\n1000000001\n10C000C001\n1000000001\n10E0000001\n1111111111" > maps/blocked_path.ber
./so_long maps/blocked_path.ber
echo "벽에 막혀서 모든 코인을 줍지 못하거나 출구로 갈 수 없는 상황 테스트 완료"