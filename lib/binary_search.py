class BinarySearch:
    def __init__(self, list: list[int]):
        self.list = list

    def isOK(self, index: int, key: int) -> bool:
        """
        index が条件を満たすかどうか
        ここを変更する
        """
        if self.list[index] >= key:
            return True
        else:
            return False

    def binary_search(self, key: int) -> int:
        """
        めぐる式2分探索
        O(logN)
        汎用的な二分探索のテンプレ
        https://qiita.com/drken/items/97e37dd6143e33a64c8c
        """
        # 「index = 0」が条件を満たすこともあるので、初期値は -1
        ng: int = -1
        # 「index = a.size()-1」
        # が条件を満たさないこともあるので、初期値は a.size()
        ok: int = len(self.list)

        # ok と ng のどちらが大きいかわからないことを考慮
        # 大小関係は関係ない。条件を満たすかどうかで変える。
        # 基本は ng < mid < ok を考える
        while abs(ok - ng) > 1:
            mid: int = (ok + ng) // 2
            if self.isOK(mid, key):
                ok = mid
            else:
                ng = mid
        return ok
