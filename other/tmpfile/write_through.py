import time
from sim_file import sim_file
from server import sim_server


class sim_cache:

    def __init__(self, server):
        self._cache_file = {}
        self._target_server = server

    def _search_cache(self, target_file):
        # search file in the cache
        return target_file in self._cache_file

    def _read_cache(self, target_file):
        # read cached file
        if self._search_cache(target_file):
            return self._cache_file[target_file].get_data()
        else:
            return None
